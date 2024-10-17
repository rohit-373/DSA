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
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int swap = 1;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            Node* current = queue[front++];
            if (swap) {
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
            printf("%d ", current->data);
        }
        printf("\n");
        swap = !swap;
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