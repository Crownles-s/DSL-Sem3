#include <stdio.h>
#define MAX 100

struct Queue {
    int items[MAX];
    int front, rear;
};

void initialize(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX-1;
}

void enqueue(struct Queue *q, int val) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty(q))
        q->front = q->rear = 0;
    else
        q->rear = (q->rear + 1) % MAX;

    q->items[q->rear] = val;

    printf("%d enqueued successfully\n", val);
}

int dequeue(struct Queue *q) {
    int value;

    if (isEmpty(q)) {
        printf("\nQueue is empty\n");
        return -1;
    }

    value = q->items[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % MAX;

    return value;
}

int main() {
    struct Queue q;
    initialize(&q);

    int n;
    printf ("Enter number of elements: ");
    scanf ("%d", &n);

    for (int i=0; i<n; i++){
        int val;
        printf("\nEnter element %d: ", i+1);
        scanf("%d", &val);
        enqueue(&q, val);
    }

    for (int i=0; i<n; i++){
        int k=dequeue(&q);
        printf("\n%d dequeued", k);
    }
}

