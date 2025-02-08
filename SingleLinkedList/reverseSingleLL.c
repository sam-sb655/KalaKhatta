#include <stdio.h>
#include <stdlib.h>
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
}
void printData(Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty");
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void reverseList(Node **head)
{
    Node *temp = NULL;
    Node *temp2 = NULL;
    while ((*head) != NULL)
    {
        temp2 = (*head)->next;
        (*head)->next = temp;
        temp = (*head);
        (*head) = temp2;
    }
    (*head) = temp;
}
int main()
{
    Node *head = NULL;
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);
    printData(head);
    reverseList(&head);
    printData(head);
    return 0;
}