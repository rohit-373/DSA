#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} Node;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrder(Node *root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

void zigZagTraversal(Node* root) {
    if (root == NULL)
        return;
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    bool leftToRight = true;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            Node* current = queue[front++];
            printf("%d ", current->data);
            if (leftToRight) {
                if (current->left != NULL)
                    queue[rear++] = current->left;
                if (current->right != NULL)
                    queue[rear++] = current->right;
            } else {
                if (current->right != NULL)
                    queue[rear++] = current->right;
                if (current->left != NULL)
                    queue[rear++] = current->left;
            }
        }
        leftToRight = !leftToRight;
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(12);
    root->right = createNode(9);
    root->left->left = createNode(5);
    root->left->right = createNode(6);

    printf("Inorder traversal:\n");
    inOrder(root);

    printf("\nPreorder traversal:\n");
    preOrder(root);

    printf("\nPostorder traversal:\n");
    postOrder(root);

    printf("\nLevel order traversal:\n");
    levelOrder(root);
    
    printf("\nZigzag traversal:\n");
    zigZagTraversal(root);

    printf("\n");
    return 0;
}
