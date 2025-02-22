#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front, size;
    int capacity;
} MyQueue;

// Function to initialize the queue
MyQueue* createQueue(int c) {
    MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
    q->arr = (int*)malloc(c * sizeof(int));
    q->capacity = c;
    q->size = 0;
    q->front = 0;
    return q;
}

// Get the front element
int getFront(MyQueue *q) {
    if (q->size == 0) 
        return -1; 
    return q->arr[q->front];
}

// Get the rear element
int getRear(MyQueue *q) {
    if (q->size == 0) 
        return -1; 
    int rear = (q->front + q->size - 1) % q->capacity;
    return q->arr[rear];
}

// Insert an element at the rear
void enqueue(MyQueue *q, int x) {
    if (q->size == q->capacity) 
        return; 
    int rear = (q->front + q->size) % q->capacity;
    q->arr[rear] = x;
    q->size++;
}

// Remove an element from the front
int dequeue(MyQueue *q) {
    if (q->size == 0) 
        return -1;
    int res = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return res;
}

// Function to free memory
void freeQueue(MyQueue *q) {
    free(q->arr);
    free(q);
}

int main() {
    MyQueue *q = createQueue(4);
    enqueue(q, 10);
    printf("%d %d\n", getFront(q), getRear(q));
    enqueue(q, 20);
    printf("%d %d\n", getFront(q), getRear(q));
    enqueue(q, 30);
    printf("%d %d\n", getFront(q), getRear(q));
    enqueue(q, 40);
    printf("%d %d\n", getFront(q), getRear(q));
    dequeue(q);
    printf("%d %d\n", getFront(q), getRear(q));
    dequeue(q);
    printf("%d %d\n", getFront(q), getRear(q));
    enqueue(q, 50);
    printf("%d %d\n", getFront(q), getRear(q));

    freeQueue(q);
    return 0;
}
