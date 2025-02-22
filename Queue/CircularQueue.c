#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct Queue
{
    int front;
    int rear;
    int *arr;
};
struct Queue *createQueue()
{
    struct Queue *ptr = (struct Queue *)malloc(sizeof(struct Queue));
    ptr->front = -1;
    ptr->rear = -1;
    ptr->arr = (int *)malloc(sizeof(int) * MAX);
    return ptr;
}
void enqueue(struct Queue **q, int x)
{
    if ((*q)->front == -1 && (*q)->rear == -1)
    {
        (*q)->front = (*q)->rear = 0;
        (*q)->arr[(*q)->rear] = x;
        return;
    }
    else if (((*q)->rear + 1) % MAX == (*q)->front)
    {
        printf("Queue is full");
        return;
    }
    else
    {
        (*q)->rear = ((*q)->rear + 1) % MAX;
        (*q)->arr[(*q)->rear] = x;
        return;
    }
}
void dequeue(struct Queue **q)
{
    if ((*q)->front == -1 && (*q)->rear == -1)
    {
        printf("Queue underflow");
        return;
    }
    else if ((*q)->front == (*q)->rear)
    {
        (*q)->front = (*q)->rear = -1;
        return;
    }
    else
    {
        (*q)->front = ((*q)->front + 1) % MAX;
    }
}
void display(struct Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        int i = q->front;
        printf("Queue is: ");
        while (i != q->rear)
        {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX;
        }
    }
}
int main()
{
    struct Queue *q = createQueue();

    // Enqueue elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50); // Queue is now full

    display(q); // Expected output: Queue is: 10 20 30 40

    printf("\nEnqueuing 60 (should show queue is full)\n");
    enqueue(&q, 60); // Should print "Queue is full"

    // Dequeue elements
    printf("\nDequeuing two elements...\n");
    dequeue(&q);
    dequeue(&q);
    display(q); // Expected output: Queue is: 30 40

    // Enqueue more elements
    printf("\nEnqueuing 60 and 70...\n");
    enqueue(&q, 60);
    enqueue(&q, 70);
    display(q); // Expected output: Queue is: 30 40 60 70

    // Dequeue all elements
    printf("\nDequeuing all elements...\n");
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    display(q); // Expected output: Queue is empty

    printf("\nTrying to dequeue from empty queue...\n");
    dequeue(&q); // Should print "Queue underflow"

    // Free memory
    free(q->arr);
    free(q);

    return 0;
}