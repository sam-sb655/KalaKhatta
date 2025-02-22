#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int size;
    int capacity;
    int front;
} Queue;

// Function to initialize queue
Queue* createQueue(int qSize) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->size = 0;
    q->front = 0;
    q->capacity = qSize;
    q->arr = (int*)malloc(qSize * sizeof(int));
    return q;
}

// Function to add an element to queue
void enqueue(Queue *q, int x) {
    // If queue is full
    if (q->size == q->capacity) {
        return;
    }

    q->arr[q->size] = x;
    q->size++;
}

// Function to pop front element from queue
void dequeue(Queue *q) {
    // If queue is empty
    if (q->size == 0) {
        return;
    }

    // Shift all the elements to the left
    for (int i = 1; i < q->size; i++) {
        q->arr[i - 1] = q->arr[i];
    }

    // Decrement queue size
    q->size--;
}

// Function to get the front element
int getFront(Queue *q) {
    // If queue is empty
    if (q->size == 0)
        return -1;

    return q->arr[q->front];
}

// Function to display the queue elements
void display(Queue *q) {
    for (int i = q->front; i < q->size; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Function to free memory
void freeQueue(Queue *q) {
    free(q->arr);
    free(q);
}

int main() {
    Queue *q = createQueue(4);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("%d\n", getFront(q));
    dequeue(q);
    enqueue(q, 4);
    display(q);

    freeQueue(q);
    return 0;
}
