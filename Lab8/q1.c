#include <stdio.h>
#define MAX 100

struct Queue{
    char name[MAX];
    int id[MAX];
    int front, rear;
};

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

int isFull(struct Queue* q) {
    return q->rear == MAX-1;
}

void enqueue(struct Queue* q, char n, int i) {
    if (isFull(q)){
        printf("Queue is full\n");
        return;
    }

    if (isEmpty(q))
        q->front = 0;

    q->name[++q->rear] = n;
    q->id[q->rear] = i;

    printf("Process ID %d queued\n", i);
}

void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Print queue is empty.\n");
        return;
    }

    int i = q->id[q->front];
    char n = q->name[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    printf ("Process ID %d printed\n", i);

}

int main(){
    struct Queue q;
    q.front=-1;
    q.rear=-1;

    printf ("Enter number of processes: ");
    int i, n;
    scanf("%d", &n);

    for (i=0; i<n; i++){
        printf("\nEnter process %d name:\n", i+1);
        char name;
        scanf("%d");
        scanf("%c", &name);
        int id = rand()%(10*n+1);

        enqueue(&q, name, id);
    }

    printf("\nAll %d tasks queued.\n\n", n);

    for (i=0; i<=n; i++){
        dequeue(&q);
    }
}
