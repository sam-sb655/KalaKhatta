#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Recursive function to reverse a linked list
struct Node* reverseRecursive(struct Node* head) {
    // Base case: If the list is empty or has only one node, return head
    if (head == NULL || head->next == NULL)
        return head;

    // Recursive call to reverse the rest of the list
    struct Node* newHead = reverseRecursive(head->next);

    // Reverse the links
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

// Function to insert a new node at the beginning of the list
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
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

    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    insertAtHead(&head, 5);
    insertAtHead(&head, 4);
    insertAtHead(&head, 3);
    insertAtHead(&head, 2);
    insertAtHead(&head, 1);

    printf("Original List:\n");
    printList(head);

    // Reverse the linked list recursively
    head = reverseRecursive(head);

    printf("Reversed List:\n");
    printList(head);

    return 0;
}
