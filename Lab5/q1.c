#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item;
    struct Node *next, *prev;
};

struct Node *head = NULL, *tail = NULL, *temp;

struct Node* createNode(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertEnd(int val) {
    struct Node *newNode = createNode(val);
    if (head == NULL)
        head = tail = newNode;

    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteEnd() {
    if (tail == NULL) return;

    temp = tail;
    if (head == tail)
        head = tail = NULL;

    else {
        tail = tail->prev;
        tail->next = NULL;
    }

    free(temp);
}

void insertPos(int pos, int val) {

    temp = head;
    for (int i = 0; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) return;

    struct Node *newNode = createNode(val);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void deletePos(int pos) {
    if (head == NULL || pos < 0) return;

    temp = head;
    for (int i = 0; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)  return;

    if (temp == tail) {
        deleteEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void insertBefore(int val, int req) {
    if (head == NULL) return;

    if (head->item == req) {
        struct Node *newNode = createNode(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    temp = head;
    while (temp != NULL && temp->item != req)
        temp = temp->next;

    if (temp == NULL) return;

    struct Node *newNode = createNode(val);
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;
    temp->prev = newNode;
}

void insertAfter(int val, int req) {
    temp = head;

    while (temp != NULL && temp->item != req)
        temp = temp->next;

    if (temp == NULL) return;

    struct Node *newNode = createNode(val);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        tail = newNode;

    temp->next = newNode;
}

void forwardTraverse() {
    temp = head;
    printf("\n");
    while (temp != NULL) {
        printf("%d\t", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

void reverseTraverse() {
    temp = tail;
    printf("\n");
    while (temp != NULL) {
        printf("%d\t", temp->item);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int choice, val, req, pos;
    printf("\nMENU:\n1.Insert End 2.Delete End 3.Insert at Pos 4.Delete at Pos 5.Insert After 6.Insert Before 7.Forward 8.Backward 9.Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(val);
                forwardTraverse();
                break;

            case 2:
                deleteEnd();
                forwardTraverse();
                break;

            case 3:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &val);
                insertPos(pos, val);
                forwardTraverse();
                break;

            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                forwardTraverse();
                break;

            case 5:
                printf("Enter value to insert, and required value: ");
                scanf("%d %d", &val, &req);
                insertAfter(val, req);
                forwardTraverse();
                break;

            case 6:
                printf("Enter value to insert, and required value: ");
                scanf("%d %d", &val, &req);
                insertBefore(val, req);
                forwardTraverse();
                break;

            case 7:
                forwardTraverse();
                break;

            case 8:
                reverseTraverse();
                break;

            case 9:
                printf("\nExited!");
                return 0;
        }
    }
}
