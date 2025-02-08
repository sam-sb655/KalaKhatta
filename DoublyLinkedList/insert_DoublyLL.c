#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Node;
void printData(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("<-%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
Node *createNode(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}
void addNode(Node **head, int data)
{
    if (*head == NULL)
    {
        *head = createNode(data);
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = createNode(data);
    temp->next->prev = temp;
}
void addInFront(Node **head, int data)
{
    Node *temp = *head;
    *head = createNode(data);
    (*head)->next = temp;
    temp->prev = (*head);
}
void addAtPosition(Node **head, int data, int position)
{
    int count = 1;
    Node *temp = *head;
    Node *temp1 = NULL;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    temp1 = temp->next;
    temp->next = createNode(data);
    temp->next->next = temp1;
    temp->next->prev = temp;
}
int main()
{
    Node *head = NULL;
    addNode(&head, 20);
    addNode(&head, 40);
    addNode(&head, 50);
    addNode(&head, 60);
    printData(head);
    addInFront(&head, 10);
    printData(head);
    addAtPosition(&head, 30, 3);
    printData(head);
}