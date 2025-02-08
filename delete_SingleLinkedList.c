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

void print_data(Node *head)
{
    if (head == NULL)
    {
        printf("Linked List is empty\n");
        return; // **Added return to prevent further execution**
    }
    Node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void deleteFromEnd(Node **head);
void deleteFromBeginning(Node **head);
void deleteAtPosition(Node **head, int position);

int main()
{
    Node *head = NULL;
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);

    print_data(head);

    deleteAtPosition(&head, 3);
    print_data(head); // Debug print

    deleteFromBeginning(&head);
    print_data(head); // Debug print

    deleteFromEnd(&head);
    print_data(head); // Debug print

    return 0;
}

void deleteFromBeginning(Node **head)
{
    if (*head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromEnd(Node **head)
{
    if (*head == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    if ((*head)->next == NULL) // Check if there's only one node
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (position == 1) // If deleting the first node
    {
        deleteFromBeginning(head);
        return;
    }

    Node *temp = *head;
    int count = 1;

    while (temp != NULL && count < position - 1) // Traverse to position-1
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) // Invalid position check
    {
        printf("Invalid position\n");
        return;
    }

    Node *t = temp->next;
    temp->next = temp->next->next;
    free(t);
}
