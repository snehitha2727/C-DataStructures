#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int data;
    Color color;
    struct Node *left, *right, *parent;
} Node;

typedef struct {
    Node *root;
    Node *TNULL;
} RedBlackTree;

Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

RedBlackTree* createTree() {
    RedBlackTree *tree = (RedBlackTree*)malloc(sizeof(RedBlackTree));
    tree->TNULL = createNode(0);
    tree->TNULL->color = BLACK;
    tree->root = tree->TNULL;
    return tree;
}

void leftRotate(RedBlackTree *tree, Node *x) {
    Node *y = x->right;
    x->right = y->left;
    if (y->left != tree->TNULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == tree->TNULL) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void rightRotate(RedBlackTree *tree, Node *x) {
    Node *y = x->left;
    x->left = y->right;
    if (y->right != tree->TNULL) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == tree->TNULL) {
        tree->root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void insertFix(RedBlackTree *tree, Node *k) {
    Node *u;
    while (k->parent->color == RED) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(tree, k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                leftRotate(tree, k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;
            if (u->color == RED) {
                u->color = BLACK;
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(tree, k);
                }
                k->parent->color = BLACK;
                k->parent->parent->color = RED;
                rightRotate(tree, k->parent->parent);
            }
        }
        if (k == tree->root) {
            break;
        }
    }
    tree->root->color = BLACK;
}

void insert(RedBlackTree *tree, int data) {
    Node *node = createNode(data);
    Node *y = tree->TNULL;
    Node *x = tree->root;

    while (x != tree->TNULL) {
        y = x;
        if (node->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    node->parent = y;
    if (y == tree->TNULL) {
        tree->root = node;
    } else if (node->data < y->data) {
        y->left = node;
    } else {
        y->right = node;
    }
    node->left = tree->TNULL;
    node->right = tree->TNULL;
    node->color = RED;

    insertFix(tree, node);
}

void inorderHelper(Node *root, Node *TNULL) {
    if (root != TNULL) {
        inorderHelper(root->left, TNULL);
        printf("%d ", root->data);
        inorderHelper(root->right, TNULL);
    }
}

void inorder(RedBlackTree *tree) {
    inorderHelper(tree->root, tree->TNULL);
}

Node* searchTreeHelper(Node *node, int key, Node *TNULL) {
    if (node == TNULL || key == node->data) {
        return node;
    }
    if (key < node->data) {
        return searchTreeHelper(node->left, key, TNULL);
    }
    return searchTreeHelper(node->right, key, TNULL);
}

Node* search(RedBlackTree *tree, int key) {
    return searchTreeHelper(tree->root, key, tree->TNULL);
}

void printTreeHelper(Node *root, Node *TNULL, int space) {
    if (root != TNULL) {
        space += 10;
        printTreeHelper(root->right, TNULL, space);
        printf("\n");
        for (int i = 10; i < space; i++) {
            printf(" ");
        }
        printf("%d(%s)\n", root->data, root->color == RED ? "R" : "B");
        printTreeHelper(root->left, TNULL, space);
    }
}

void printTree(RedBlackTree *tree) {
    printTreeHelper(tree->root, tree->TNULL, 0);
}

int main() {
    RedBlackTree *tree = createTree();

    int values[] = {20, 15, 25, 10, 5, 1, 30};
    for (int i = 0; i < 7; i++) {
        insert(tree, values[i]);
    }

    printf("Inorder Traversal: ");
    inorder(tree);
    printf("\n");

    int searchKey = 25;
    Node *result = search(tree, searchKey);
   
::contentReference[oaicite:11]{index=11}
 
