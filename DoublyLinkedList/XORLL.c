#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* npx; // XOR of next and previous node addresses
};

// XOR function for pointer manipulation
struct Node* XOR(struct Node* a, struct Node* b) {
    return (struct Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

// Insert node at the beginning of the XOR Linked List
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->npx = *head; // XOR(NULL, current head) = current head

    if (*head != NULL) {
        (*head)->npx = XOR(newNode, (*head)->npx);
    }

    *head = newNode; // Move head to the new node
}

// Print the XOR Linked List in forward direction
void printList(struct Node* head) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next;

    printf("XOR Linked List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);

        next = XOR(prev, curr->npx); // Compute next node
        prev = curr;
        curr = next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Inserting nodes at the beginning
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);
    insertAtHead(&head, 40);
    insertAtHead(&head, 50);

    // Printing the XOR Linked List
    printList(head);

    return 0;
}
