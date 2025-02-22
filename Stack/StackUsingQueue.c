#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Structure for a queue
typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

// Function to create an empty queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if a queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Function to enqueue an element
void enqueue(Queue* q, int x) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = x;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    return data;
}

// Structure for a stack using two queues
typedef struct Stack {
    Queue* q1;
    Queue* q2;
} Stack;

// Function to create a stack
Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->q1 = createQueue();
    s->q2 = createQueue();
    return s;
}

// Function to push an element onto the stack
void push(Stack* s, int x) {
    // Push x first into empty q2
    enqueue(s->q2, x);

    // Push all remaining elements of q1 into q2
    while (!isEmpty(s->q1)) {
        enqueue(s->q2, dequeue(s->q1));
    }

    // Swap the names of q1 and q2
    Queue* temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

// Function to pop an element from the stack
void pop(Stack* s) {
    if (isEmpty(s->q1)) {
        return;
    }
    dequeue(s->q1);
}

// Function to get the top element of the stack
int top(Stack* s) {
    if (isEmpty(s->q1)) {
        return -1;
    }
    return s->q1->front->data;
}

// Function to get the size of the stack
int size(Stack* s) {
    QueueNode* temp = s->q1->front;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Driver code
int main() {
    Stack* s = createStack();
    
    push(s, 1);
    push(s, 2);
    push(s, 3);

    printf("Current size: %d\n", size(s));
    printf("%d\n", top(s));
    pop(s);
    printf("%d\n", top(s));
    pop(s);
    printf("%d\n", top(s));
    
    printf("Current size: %d\n", size(s));

    // Free allocated memory
    free(s->q1);
    free(s->q2);
    free(s);

    return 0;
}
