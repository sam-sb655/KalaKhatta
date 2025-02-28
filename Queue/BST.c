#include <stdio.h>
#include <stdlib.h>

// Definition of a Node
typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert an element into the tree
Node* insert(Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Find the minimum node (used in delete function)
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete an element from the tree
Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search for an element in the tree
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

// Inorder traversal (Left, Root, Right)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal (Root, Left, Right)
void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (Left, Right, Root)
void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Finding the size of the tree
int size(Node* root) {
    if (root == NULL) return 0;
    return 1 + size(root->left) + size(root->right);
}

// Finding the height of the tree
int height(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Find the level with maximum sum
int findMaxLevelSum(Node* root) {
    if (!root) return 0;
    int maxSum = 0, levelSum;
    int queueSize, i;
    Node** queue = (Node**)malloc(1000 * sizeof(Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        queueSize = rear - front;
        levelSum = 0;
        for (i = 0; i < queueSize; i++) {
            Node* current = queue[front++];
            levelSum += current->data;
            if (current->left) queue[rear++] = current->left;
            if (current->right) queue[rear++] = current->right;
        }
        if (levelSum > maxSum) maxSum = levelSum;
    }

    free(queue);
    return maxSum;
}

// Find the Least Common Ancestor (LCA) of two nodes
Node* findLCA(Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data == n1 || root->data == n2) return root;

    Node* leftLCA = findLCA(root->left, n1, n2);
    Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA) return root;
    return leftLCA ? leftLCA : rightLCA;
}

// Main function
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    printf("Size of tree: %d\n", size(root));
    printf("Height of tree: %d\n", height(root));

    int key = 40;
    if (search(root, key))
        printf("%d found in the tree\n", key);
    else
        printf("%d not found in the tree\n", key);

    root = deleteNode(root, 40);
    printf("After deleting 40, Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Maximum sum level: %d\n", findMaxLevelSum(root));

    Node* lca = findLCA(root, 20, 60);
    if (lca)
        printf("LCA of 20 and 60: %d\n", lca->data);
    else
        printf("LCA not found\n");

    return 0;
}
