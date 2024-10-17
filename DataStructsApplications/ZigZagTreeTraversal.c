#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void zigZagTraversal(Node* root) {
    if (root == NULL)
        return;
    Node* currentLevel[100];
    Node* nextLevel[100];
    int currentLevelSize = 0;
    int nextLevelSize = 0;
    int leftToRight = 0;
    currentLevel[currentLevelSize++] = root;
    while (currentLevelSize > 0) {
        Node* node = currentLevel[--currentLevelSize];
        printf("%d ", node->data);
        if (leftToRight) {
            if (node->left != NULL)
                nextLevel[nextLevelSize++] = node->left;
            if (node->right != NULL)
                nextLevel[nextLevelSize++] = node->right;
        } else {
            if (node->right != NULL)
                nextLevel[nextLevelSize++] = node->right;
            if (node->left != NULL)
                nextLevel[nextLevelSize++] = node->left;
        }
        if (currentLevelSize == 0) {
            leftToRight = 1 - leftToRight;
            currentLevelSize = nextLevelSize;
            nextLevelSize = 0;
            for (int i = 0; i < currentLevelSize; i++)
                currentLevel[i] = nextLevel[i];
        }
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(7);
    root->left->right = createNode(6);
    root->right->left = createNode(5);
    root->right->right = createNode(4);
    zigZagTraversal(root);
    return 0;
}