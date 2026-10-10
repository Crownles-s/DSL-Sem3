#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct stack {
    struct node* treeNode;
    struct stack* next;
};

struct Stack {
    struct stack *top;
};

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

    printf("Left node:\n");
    root->left = createTree();

    printf("Right node:\n");
    root->right = createTree();

    return root;
}

void push(struct Stack *s, struct node *treeNode) {
    struct stack *newNode = (struct stack*)malloc(sizeof(struct stack));
    newNode->treeNode = treeNode;
    newNode->next = s->top;
    s->top = newNode;
}

struct node* pop(struct Stack *s) {
    if (s->top == NULL) return NULL;
    struct stack *temp = s->top;
    struct node *Node = temp->treeNode;
    s->top = s->top->next;
    free(temp);
    return Node;
}

int isEmpty(struct Stack *s) {
    return s->top == NULL;
}

void inorder(struct node *root) {
    struct Stack s = { NULL };
    struct node *temp = root;

    printf("Inorder: ");
    while (temp != NULL || !isEmpty(&s)) {
        while (temp != NULL) {
            push(&s, temp);
            temp = temp->left;
        }
        temp = pop(&s);
        printf("%d ", temp->data);
        temp = temp->right;
    }
    printf("\n");
}

void postorder(struct node *root) {
    if (root == NULL) return;
    struct Stack s1 = { NULL };
    struct Stack s2 = { NULL };

    push(&s1, root);
    while (!isEmpty(&s1)) {
        struct node *temp = pop(&s1);
        push(&s2, temp);

        if (temp->left) push(&s1, temp->left);
        if (temp->right) push(&s1, temp->right);
    }

    printf("Postorder: ");
    while (!isEmpty(&s2)) {
        struct node *temp = pop(&s2);
        printf("%d ", temp->data);
    }
    printf("\n");
}

void preorder(struct node *root) {
    if (root == NULL) return;
    struct Stack s = { NULL };
    push(&s, root);

    printf("Preorder: ");
    while (!isEmpty(&s)) {
        struct node *temp = pop(&s);
        printf("%d ", temp->data);

        if (temp->right) push(&s, temp->right);
        if (temp->left) push(&s, temp->left);
    }
    printf("\n");
}

void printParent(struct node *root, int val) {
    if (root == NULL) return;

    if (root->data == val) {
        printf("Root node\n");
        return;
    }

    if ((root->left && root->left->data == val) || (root->right && root->right->data == val)) {
        printf("Parent is %d\n", root->data);
        return;
    }

    printParent(root->left, val);
    printParent(root->right, val);
}

int findHeight(struct node *root) {
    if (root == NULL) return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printDepth(struct node *root) {
    if (root == NULL) {
        printf("Depth is: 0\n");
        return;
    }
    int i = findHeight(root);
    printf("Depth: %d\n", i);
}

int printAncestorsUtil(struct node *root, int val) {
    if (root == NULL) return 0;

    if (root->data == val) return 1;

    if (printAncestorsUtil(root->left, val) || printAncestorsUtil(root->right, val)) {
        printf("%d ", root->data);
        return 1;
    }

    return 0;
}

void printAncestors(struct node *root, int val) {
    if (root == NULL) return;

    if (root->data == val) {
        printf("Root node has no ancestors\n");
        return;
    }
    printf("Ancestors of %d: ", val);
    if (!printAncestorsUtil(root, val)) printf("Node not found.");

    printf("\n");
}

int countLeafNodes(struct node *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct node *root = NULL;
    int choice, val;

    printf("\nMENU: 1.Create 2.Inorder 3.Preorder 4.Postorder 5.Parent 6.Depth 7.Ancestors 8.Count Leaves 9.Exit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = createTree();
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                printf("Enter node value: ");
                scanf("%d", &val);
                printParent(root, val);
                break;
            case 6:
                printDepth(root);
                break;
            case 7:
                printf("Enter node value: ");
                scanf("%d", &val);
                printAncestors(root, val);
                break;
            case 8:
                printf("Leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 9:
                return 0;
        }
    }
}
