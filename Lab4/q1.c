#include <stdio.h>
#include <stdlib.h>

struct Node{
    int item;
    struct Node *next;
};

struct Node *head = NULL;

void createNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode -> item = val;
    newNode -> next = NULL;

    if (head == NULL){
        head = newNode;
    }
    else{
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int listSize(){
    int size=0;

    struct Node *temp = head;
    while (temp != NULL){
        size++;
        temp = temp->next;
    }

    return size;
}

void insertBefore(int val, int req){
    if (head == NULL) return;

    if (head->item == req) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->item = val;
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp, *prev;
    temp = head;

    while (temp != NULL && temp->item != req){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        printf("%d not in list", req);
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item = val;
    newNode->next = prev->next;
    prev->next = newNode;
}

void insertAfter(int val, int req){
    struct Node *temp = head;

    while (temp != NULL && temp->item != req){
        temp = temp->next;
    }

    if (temp == NULL){
        printf("%d not in list", req);
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->item = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteInt(int req){
    if (head == NULL) return;

    if (head->item == req) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node *temp, *prev;
    temp = head;

    while (temp != NULL && temp->item != req){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        printf("%d not in list", req);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display(){
    struct Node *temp;
    temp = head;

    printf("\n");
    while (temp != NULL){
        printf("%d\t", temp->item);
        temp = temp->next;
    }
}

void reverse() {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void sort(){
    int n = listSize();

    if (n <= 1) return;

    int swap;
    struct Node *temp;

    for (int i = 0; i < n - 1; i++){
        temp = head;

        for (int j = 0; j < n - i - 1; j++){
            if (temp->item > temp->next->item){
                swap = temp->next->item;
                temp->next->item = temp->item;
                temp->item = swap;
            }

            temp = temp->next;
        }
    }
}

void deleteAlt() {
    if (head == NULL || head->next == NULL) return;

    struct Node *prev = head;
    struct Node *temp = head->next;

    while (prev!=NULL && temp!=NULL) {
        prev->next = temp->next;
        free(temp);
        prev = prev->next;

        if (prev != NULL) {
            temp = prev->next;
        }
        else {
            temp = NULL;
        }
    }
}

void insertSorted(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if (head == NULL || head->item > val) {
        newNode->item = val;
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node *temp, *prev;
    temp = head;

    while (temp != NULL && temp->item <= val){
        prev = temp;
        temp = temp->next;
    }

    newNode->item = val;
    newNode->next = prev->next;
    prev->next = newNode;
}

void main(){
    printf("Enter list size: ");
    int n;
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        printf("Enter element: ");
        int val;
        scanf("%d", &val);
        createNode(val);
    }

    printf("List is:\n");
    display();

    int choice, val, req;

    while(1){

    printf("\n\nMENU:\n1.Insert before 2.Insert After 3.Delete 4.Display 5.Reverse 6.Sort 7.Delete alternate 8.Insert&Sort 9.Exit\n");
    printf("Enter choice: ");
    scanf ("%d", &choice);

    switch(choice){
    case 1:
        printf("Enter value to insert, and required value: ");
        scanf("%d %d", &val ,&req);
        insertBefore(val, req);
        printf("Inserted");
        display();
        break;

    case 2:
        printf("Enter value to insert, and required value: ");
        scanf("%d %d", &val ,&req);
        insertAfter(val, req);
        printf("Inserted");
        display();
        break;

    case 3:
        printf("Enter required value: ");
        scanf("%d", &req);
        deleteInt(req);
        printf("Deleted");
        display();
        break;

    case 4:
        display();
        break;

    case 5:
        reverse();
        printf("Reversed");
        display();
        break;

    case 6:
        sort();
        printf("Sorted");
        display();
        break;

    case 7:
        deleteAlt();
        printf("Deleted alternate nodes");
        display();
        break;

    case 8:
        printf("Enter value: ");
        scanf("%d", &val);
        insertSorted(val);
        printf("Inserted");
        display();
        break;

    case 9:
        return;
    }

    }
}
