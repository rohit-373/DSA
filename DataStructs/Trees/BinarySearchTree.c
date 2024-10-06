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

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (root->data < data)
        return search(root->right, data);
    return search(root->left, data);
}

Node* insert(Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

Node* minValue(Node* root) {
    Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* maxValue(Node* root) {
    Node* current = root;
    while (current->right != NULL)
        current = current->right;
    return current;
}

int inOrderSuccessor(Node* root, int pos) {
    Node* current = search(root, pos);
    if (current == NULL)
        return -1;
    if (current->right != NULL)
        return minValue(current->right)->data;
    Node* successor = NULL;
    Node* ancestor = root;
    while (ancestor != current) {
        if (current->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else
            ancestor = ancestor->right;
    }
    return successor->data;
}

Node* delete(Node* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = delete(root->left, data);
    else if (data > root->data)
        root->right = delete(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL) {
            Node* temp = root;
            root = NULL;
            free(temp);
        } else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            Node* temp = minValue(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node* root = createNode(12);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 13);
    insert(root, 17);
    insert(root, 1);
    insert(root, 9);
    insert(root, 19);

    printf("Inorder traversal of the given tree:\n");
    inOrder(root);

    // delete no child
    //root = delete(root, 19);

    // delete one child 
    //root = delete(root, 17);

    // delete two children
    root = delete(root, 5);

    printf("\nInorder traversal of the modified tree:\n");
    inOrder(root);
    return 0;
}
