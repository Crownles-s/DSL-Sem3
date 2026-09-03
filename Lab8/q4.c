#include <stdio.h>
#include <stdlib.h>

struct Node {
    int age;
    char name;
    int priority;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

void initialize(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

void enqueue(struct Queue *q, int a, char n, int p) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->age = a;
    newnode->name = n;
    newnode->priority = p;
    newnode->next = NULL;

    // Insert based on priority (lower number = higher priority)
    if (isEmpty(q) || p < q->front->priority) {
        newnode->next = q->front;
        q->front = newnode;
        if (q->rear == NULL) {
            q->rear = newnode;
        }
    } else {
        struct Node *current = q->front;
        while (current->next != NULL && current->next->priority <= p) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
        if (newnode->next == NULL) {
            q->rear = newnode;
        }
    }

    printf("Patient %c enqueued (Priority: %d)\n", n, p);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue empty\n");
        return;
    }

    struct Node *temp = q->front;
    printf("Treated Patient %c \n", temp->name);

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

int main() {
    struct Queue q;
    initialize(&q);

    enqueue(&q, 30, 'B', 1);
    enqueue(&q, 60, 'C', 2);
    printf("\n");

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
}
