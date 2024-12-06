#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary tree
struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Preorder Traversal: Root -> Left -> Right
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->value);  // Visit the root
        preorder(root->left);        // Traverse the left subtree
        preorder(root->right);       // Traverse the right subtree
    }
}

// Inorder Traversal: Left -> Root -> Right
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);         // Traverse the left subtree
        printf("%d ", root->value);  // Visit the root
        inorder(root->right);        // Traverse the right subtree
    }
}

// Postorder Traversal: Left -> Right -> Root
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);       // Traverse the left subtree
        postorder(root->right);      // Traverse the right subtree
        printf("%d ", root->value);  // Visit the root
    }
}

// Main function
int main() {
    // Create the root node and other nodes
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Print traversals
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}



// OUTPUT
// Preorder Traversal: 1 2 4 5 3 6 7 
// Inorder Traversal: 4 2 5 1 6 3 7 
// Postorder Traversal: 4 5 2 6 7 3 1 
// Program ended with exit code: 0
