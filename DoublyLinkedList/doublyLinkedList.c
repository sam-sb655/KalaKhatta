#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;
Node *createNode(int data);
void addNode(Node **head, int data);
void findLength(Node *head);
void printData(Node *head);
int main()
{
    Node *head = NULL;
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    findLength(head);
    printData(head);
    return 0;
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
void findLength(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    printf("Length of the Linked List : %d\n", count);
}
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
}