#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
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

void enqueue(struct Queue *q, int val) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = val;
    newnode->next = NULL;

    if (q->rear == NULL)
        q->front = q->rear = newnode;
    else {
        q->rear->next = newnode;
        q->rear = newnode;
    }

    printf("%d enqueued\n", val);
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue empty\n");
        return -1;
    }

    struct Node *temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return val;
}

int main() {
    struct Queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("\n");

    printf("Dequeued %d\n", dequeue(&q));
    printf("Dequeued %d\n", dequeue(&q));
    dequeue(&q);
}
