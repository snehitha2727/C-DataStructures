/* AVL TREE WITH DELETION */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

// Utility functions
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* N) {
    return (N == NULL) ? 0 : N->height;
}

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Right rotate
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor
int getBalance(struct Node* node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

// Insert node
struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    // Rebalance cases
    if (balance > 1 && key < node->left->data)
        return rightRotate(node);
    if (balance < -1 && key > node->right->data)
        return leftRotate(node);
    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find minimum node in subtree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    // Standard BST delete
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // One child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            // Node with two children
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Rebalance
    int balance = getBalance(root);

    // Left Left
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Create AVL tree
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        root = insert(root, values[i]);

    printf("Inorder traversal of AVL tree:\n");
    inorder(root);
    printf("\n");

    // Delete nodes
    root = deleteNode(root, 20);
    printf("After deleting 20:\n");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("After deleting 30:\n");
    inorder(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("After deleting 50:\n");
    inorder(root);
    printf("\n");

    return 0;
}
