#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct queue {
    struct node* treeNode;
    struct queue* next;
};

struct queue* front = NULL;
struct queue* rear = NULL;

void enqueue(struct node* value) {
    struct queue* newNode = (struct queue*)malloc(sizeof(struct queue));
    newNode->treeNode = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

struct node* dequeue() {
    if (front == NULL) return NULL;

    struct queue* temp = front;
    struct node* treeNode = temp->treeNode;

    front = front->next;

    if (front == NULL) rear = NULL;

    free(temp);
    return treeNode;
}

struct node* createTree() {
    int x;

    printf("Enter -1 to stop: ");
    scanf("%d", &x);

    if (x == -1) return NULL;

    int val;
    printf("Enter data: ");
    scanf("%d", &val);

    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = val;

    printf("Left node: ");
    root->left = createTree();

    printf("Right node: ");
    root->right = createTree();

    return root;
}

void levelOrder(struct node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (front != NULL) {
        struct node* current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL) enqueue(current->left);
        if (current->right != NULL) enqueue(current->right);
    }
}

int main() {
    struct node* root = createTree();
    printf("\nLevel Order Traversal: ");
    levelOrder(root);
    printf("\n");
}
