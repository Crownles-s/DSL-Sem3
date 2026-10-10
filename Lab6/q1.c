#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

struct Node* createNode(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item = val;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(int val) {
    struct Node *newNode = createNode(val);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = newNode;
    }
    else if (head == tail) {
        head->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void deleteStart() {
    if (head == NULL) return;

    struct Node *temp = head;

    if (head == tail) {
        head = tail = NULL;
        free(temp);
        return;
    }

    head = head->next;
    tail->next = head;
    free(temp);
}

void deleteEnd() {
    if (head == NULL) return;

    if (head == tail) {
        struct Node *temp = head;
        head = tail = NULL;
        free(temp);
        return;
    }

    struct Node *temp = head;
    while (temp->next != tail)
        temp = temp->next;

    temp->next = head;
    free(tail);
    tail = temp;
}

void display() {
    if (head == NULL) return;

    struct Node *temp = head;
    printf("\n");

    do {
        printf("%d\t", temp->item);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    int k, choice;

    printf("\nMENU: 1. Insert End, 2. Delete Start, 3.Delete End, 4.Display, 5.Exit\n");

    while(1){
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &k);
                insertEnd(k);
                display();
                break;

            case 2:
                deleteStart();
                display();
                break;

            case 3:
                deleteEnd();
                display();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }

}
