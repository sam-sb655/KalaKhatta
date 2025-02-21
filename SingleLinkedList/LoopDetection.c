#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to detect a loop in a linked list using Floyd’s Cycle Detection Algorithm
int detectLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow pointer one step
        fast = fast->next->next;    // Move fast pointer two steps

        if (slow == fast) {         // If they meet, loop exists
            return 1;
        }
    }
    return 0;  // No loop detected
}

// Function to insert a node at the beginning of the linked list
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to create a loop in the linked list (for testing purposes)
void createLoop(struct Node* head, int position) {
    if (head == NULL) return;

    struct Node* temp = head;
    struct Node* loopNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == position) {
            loopNode = temp;  // Save the node at the given position
        }
        temp = temp->next;
        count++;
    }
    temp->next = loopNode;  // Create a loop
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

    // Creating a loop for testing (linking last node to the 3rd node)
    createLoop(head, 3);

    // Detect loop
    if (detectLoop(head))
        printf("Loop detected in the linked list!\n");
    else
        printf("No loop detected.\n");

    return 0;
}
