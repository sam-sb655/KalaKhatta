#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
void insert_at_end(Node **head, int data);
void insert_at_beg(Node **head, int data);
void insert_at_position(Node **head, int data, int position);
void print_data(Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
        return;
    }
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    Node *head = NULL;
    insert_at_end(&head, 20);
    insert_at_end(&head, 40);
    insert_at_end(&head, 50);
    insert_at_beg(&head, 10);
    insert_at_position(&head, 30, 3);
    print_data(head);
    return 0;
}
void insert_at_end(Node **head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
}
void insert_at_beg(Node **head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    Node *temp = *head;
    *head = ptr;
    ptr->next = temp;
}
void insert_at_position(Node **head, int data, int position)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    Node *temp = *head;
    while ((position - 2) != 0)
    {
        temp = temp->next;
        position--;
    }
    Node *t = temp->next;
    temp->next = ptr;
    ptr->next = t;
}
