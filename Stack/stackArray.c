#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct stack
{
    int *arr;
    int top;
} Stack;
Stack *createStack()
{
    Stack *ptr = (Stack *)malloc(sizeof(Stack));
    ptr->top = -1;
    ptr->arr = (int *)malloc(sizeof(int) * MAX);
    return ptr;
}
int isFull(Stack **stack)
{
    if ((*stack)->top == MAX - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Stack **stack)
{
    if ((*stack)->top == -1)
    {
        return 1;
    }
    return 0;
}
int pop(Stack **stack)
{
    if (isEmpty(stack))
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    return (*stack)->arr[(*stack)->top--];
}

void push(Stack **stack, int data)
{
    if (isFull(stack))
    {
        printf("\nStack Overflow\n");
        return;
    }
    (*stack)->top = (*stack)->top + 1;
    (*stack)->arr[(*stack)->top] = data;
}
int main()
{
    Stack *stack = createStack();
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);
    printf("%d ", pop(&stack));
    printf("%d ", pop(&stack));
    printf("%d ", pop(&stack));
    printf("%d ", pop(&stack));
    printf("%d ", pop(&stack));
    printf("%d ", pop(&stack));

    return 0;
}