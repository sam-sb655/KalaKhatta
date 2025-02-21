#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse a linked list iteratively
struct Node* reverseIterative(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move prev one step ahead
        current = next;       // Move current one step ahead
    }
    return prev; // New head of the reversed list
}

// Function to reverse a linked list recursively
struct Node* reverseRecursive(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

// Function to insert a new node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);

    printf("Original List:\n");
    printList(head);

    head = reverseIterative(head);
    printf("Reversed List (Iterative):\n");
    printList(head);

    head = reverseRecursive(head);
    printf("Reversed List (Recursive):\n");
    printList(head);

    return 0;
}
