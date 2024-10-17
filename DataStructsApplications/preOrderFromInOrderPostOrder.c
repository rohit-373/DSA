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

Node* buildTree(int inOrder[], int postOrder[], int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd)
        return NULL;
    Node* root = createNode(postOrder[postEnd]);
    int inIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inOrder[i] == root->data) {
            inIndex = i;
            break;
        }
    }
    root->left = buildTree(inOrder, postOrder, inStart, inIndex - 1, postStart, postStart + inIndex - inStart - 1);
    root->right = buildTree(inOrder, postOrder, inIndex + 1, inEnd, postStart + inIndex - inStart, postEnd - 1);
    return root;
}

void preOrder(Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int inOrder[] = {4, 2, 5, 1, 3, 6};
    int postOrder[] = {4, 5, 2, 6, 3, 1};
    Node* root = buildTree(inOrder, postOrder, 0, 5, 0, 5);
    preOrder(root);
    return 0;
}