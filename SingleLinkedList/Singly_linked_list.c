#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
void count_of_node(Node *head);
void print_data(Node *head);
int main()
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 10;
    head->next = NULL;
    Node *current = (Node *)malloc(sizeof(Node)); // Adding a second node
    current->data = 20;
    current->next = NULL;
    head->next = current;
    // Adding a 3rd node
    // Method:1 (Naive maethod)
    Node *current2 = (Node *)malloc(sizeof(Node));
    current2->data = 30;
    current2->next = NULL;
    current->next = current2;
    // Method: 2
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (Node *)malloc(sizeof(Node));
    temp->next->data = 40;
    temp->next->next = NULL;
    // counting the number of nodes
    count_of_node(head);
    printf("\n");
    print_data(head);

    return 0;
}
void count_of_node(Node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    Node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("%d", count);
}
void print_data(Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty");
    }
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}