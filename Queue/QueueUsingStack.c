#include <stdio.h>
#include <stdlib.h>

// Structure for a stack node
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Structure for a stack
typedef struct Stack {
    StackNode* top;
} Stack;

// Function to create a new stack node
StackNode* newStackNode(int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create an empty stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    StackNode* node = newStackNode(data);
    node->next = stack->top;
    stack->top = node;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    StackNode* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped;
}

// Structure for a queue using two stacks
typedef struct Queue {
    Stack* s1;
    Stack* s2;
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->s1 = createStack();
    q->s2 = createStack();
    return q;
}

// Function to enqueue an element into the queue
void enQueue(Queue* q, int x) {
    // Move all elements from s1 to s2
    while (!isEmpty(q->s1)) {
        push(q->s2, pop(q->s1));
    }

    // Push item into s1
    push(q->s1, x);

    // Move everything back to s1
    while (!isEmpty(q->s2)) {
        push(q->s1, pop(q->s2));
    }
}

// Function to dequeue an element from the queue
int deQueue(Queue* q) {
    if (isEmpty(q->s1)) {
        return -1;
    }
    return pop(q->s1);
}

// Driver code
int main() {
    Queue* q = createQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);

    printf("%d\n", deQueue(q));
    printf("%d\n", deQueue(q));
    printf("%d\n", deQueue(q));

    // Free allocated memory
    free(q->s1);
    free(q->s2);
    free(q);

    return 0;
}
