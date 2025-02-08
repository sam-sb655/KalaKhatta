#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Node;
Node *createNode(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->prev = NULL;
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
    temp->next->prev = temp;
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
    printf("\n");
}
void deleteFromEnd(Node **head)
{
    if (*head == NULL)
    {
        printf("List is Empty");
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}
void deleteFromBeg(Node **head)
{
    if (*head == NULL)
    {
        printf("List is Empty");
        return;
    }
    Node *temp = *head;
    (*head) = temp->next;
    temp->next->prev = NULL;
    free(temp);
}
void deleteFromMid(Node **head, int position)
{
    int count = 1;
    Node *temp = *head;
    Node *temp1 = NULL, *temp2 = NULL;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    temp1 = temp->next;
    temp->next->next->prev = temp;
    temp->next = temp->next->next;
    free(temp1);
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
    deleteFromMid(&head, 3);
    printData(head);
    deleteFromBeg(&head);
    printData(head);
    deleteFromEnd(&head);
    printData(head);

    return 0;
}
