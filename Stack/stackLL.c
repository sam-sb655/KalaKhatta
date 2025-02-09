#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *createNode(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}
typedef struct stack
{
    Node *head;
} Stack;
void initializeStack(Stack *stack)
{
    stack->head = NULL;
}
int isEmpty(Stack *stack)
{
    if (stack->head == NULL)
    {
        return 1;
    }
    return 0;
}
void push(Stack *stack, int data)
{
    if (stack->head == NULL)
    {
        stack->head = createNode(data);
        return;
    }
    Node *temp = createNode(data);
    temp->next = stack->head;
    stack->head = temp;
}
void pop(Stack *stack)
{
    if (stack->head == NULL)
    {
        printf("\nStack underflow\n");
        return;
    }
    Node *temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
}
void printList(Stack *stack)
{
    Node *temp = stack->head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    Stack stack;
    initializeStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    printList(&stack);
    pop(&stack);
    printList(&stack);
    pop(&stack);
    printList(&stack);
    pop(&stack);
    printList(&stack);
    pop(&stack);
    printList(&stack);
    pop(&stack);
    printList(&stack);
    pop(&stack);
    printList(&stack);
    return 0;
}