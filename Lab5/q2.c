#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item;
    struct Node *next, *prev;
};

struct Node* createList() {
    int n, val;
    struct Node *head = NULL, *tail = NULL;

    printf("Enter list size: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &val);

        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->item = val;
        newNode->next = NULL;
        newNode->prev = tail;

        if (head == NULL)
            head = newNode;

        else
            tail->next = newNode;

        tail = newNode;
    }
    return head;
}

void display(struct Node *head) {
    printf("\nList: ");
    while (head != NULL) {
        printf("%d\t", head->item);
        head = head->next;
    }

    printf("\n");
}

int main() {
    printf("LIST 1:\n");
    struct Node *head1 = createList();
    display(head1);

    printf("\nLIST 2:\n");
    struct Node *head2 = createList();
    display(head2);

    struct Node *tail1 = head1;
    while (tail1->next != NULL) tail1 = tail1->next;

    tail1->next = head2;
    head2->prev = tail1;

    printf("\nConcatenated!");
    display(head1 != NULL ? head1 : head2);
}
