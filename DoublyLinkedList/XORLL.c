#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Node structure
struct Node {
    int data;
    struct Node* npx; // XOR of next and previous node addresses
};

// XOR function for pointer manipulation
struct Node* XOR(struct Node* a, struct Node* b) {
    return (struct Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

// Insert node at the beginning
void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->npx = *head; 

    if (*head != NULL) {
        (*head)->npx = XOR(newNode, (*head)->npx);
    }
    *head = newNode;
}

// Insert node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->npx = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* curr = *head;
    struct Node* prev = NULL;
    struct Node* next;

    while (XOR(prev, curr->npx) != NULL) {
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }

    curr->npx = XOR(prev, newNode);
    newNode->npx = curr;
}

// Delete node from beginning
void deleteFromHead(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* next = temp->npx;

    if (next != NULL) {
        next->npx = XOR(temp, next->npx);
    }

    *head = next;
    free(temp);
}

// Delete node from end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* curr = *head;
    struct Node* prev = NULL;
    struct Node* next;

    while (XOR(prev, curr->npx) != NULL) {
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }

    if (prev != NULL) {
        prev->npx = XOR(prev->npx, curr);
    } else {
        *head = NULL;
    }

    free(curr);
}

// Search for an element
int search(struct Node* head, int key) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next;
    int pos = 1;

    while (curr != NULL) {
        if (curr->data == key) {
            return pos;
        }
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
        pos++;
    }
    return -1;
}

// Count nodes in the list
int countNodes(struct Node* head) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next;
    int count = 0;

    while (curr != NULL) {
        count++;
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    return count;
}

// Print the XOR Linked List in forward direction
void printList(struct Node* head) {
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next;

    printf("XOR Linked List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    printf("NULL\n");
}

// Print the XOR Linked List in reverse direction
void printReverse(struct Node* head) {
    if (head == NULL) return;

    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next;

    while (XOR(prev, curr->npx) != NULL) {
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }

    printf("Reverse: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    printf("NULL\n");
}

// Free the entire list
void clearList(struct Node** head) {
    struct Node* curr = *head;
    struct Node* prev = NULL;
    struct Node* next;

    while (curr != NULL) {
        next = XOR(prev, curr->npx);
        free(curr);
        prev = curr;
        curr = next;
    }
    *head = NULL;
}

// Main function
int main() {
    struct Node* head = NULL;

    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);
    insertAtHead(&head, 40);
    insertAtEnd(&head, 5);

    printList(head);
    printReverse(head);

    printf("Total Nodes: %d\n", countNodes(head));

    int searchKey = 20;
    int position = search(head, searchKey);
    if (position != -1) {
        printf("Element %d found at position %d\n", searchKey, position);
    } else {
        printf("Element %d not found in the list.\n", searchKey);
    }

    deleteFromHead(&head);
    printList(head);

    deleteFromEnd(&head);
    printList(head);

    clearList(&head);
    printList(head);

    return 0;
}
