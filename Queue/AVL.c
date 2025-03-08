#include <stdio.h>
#include <stdlib.h>

// Structure for an AVL Tree Node
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Function to get the height of the node
int getHeight(Node *n) {
    return (n == NULL) ? 0 : n->height;
}

// Function to get the balance factor
int getBalanceFactor(Node *n) {
    return (n == NULL) ? 0 : getHeight(n->left) - getHeight(n->right);
}

// Function to create a new node
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;  // New node is initially added at height 1
    return node;
}

// Right rotate
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x; // New root
}

// Left rotate
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y; // New root
}

// Insert a key in the AVL tree
Node* insert(Node* node, int key) {
    // Perform standard BST insertion
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;  // No duplicate keys allowed

    // Update height
    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    // Get balance factor
    int balance = getBalanceFactor(node);

    // Perform rotations if unbalanced

    // Left-Left Case (Right Rotation)
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right-Right Case (Left Rotation)
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left-Right Case (Left-Right Rotation)
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right-Left Case (Right-Left Rotation)
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find the node with the minimum value
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node from AVL tree
Node* deleteNode(Node* root, int key) {
    // Standard BST deletion
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp; // Copy contents of non-null child

            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    // Update height
    root->height = 1 + (getHeight(root->left) > getHeight(root->right) ? getHeight(root->left) : getHeight(root->right));

    // Get balance factor
    int balance = getBalanceFactor(root);

    // Left-Left Case
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left-Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right-Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Function to search for a key in the AVL tree
Node* search(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

// Function to perform in-order traversal
void inOrder(Node *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Function to print the tree in 2D format (for visualization)
void printTree(Node *root, int space) {
    if (root == NULL)
        return;
    space += 10;
    printTree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
    printTree(root->left, space);
}

// Driver code
int main() {
    Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display Inorder\n5. Print Tree\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL)
                    printf("Key %d found!\n", key);
                else
                    printf("Key %d not found!\n", key);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("AVL Tree Structure:\n");
                printTree(root, 0);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
