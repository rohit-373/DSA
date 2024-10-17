#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void display(Node* head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("null\n");
}

void append(Node** head, Node* newNode) {
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* curr = *head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
}

void insert(Node** head, Node* newNode, int index) {
    if (index == 0) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    Node* curr = *head;
    for (int i = 0; i < index-1 && curr->next != NULL; i++)
        curr = curr->next;
    if (curr->next != NULL) {
        newNode->next = curr->next;
        curr->next = newNode;
        newNode->prev = curr;
        newNode->next->prev = newNode;
    }
}

int deleteNode(Node** head, int index) {
    int deletedValue = -1;
    if (index == 0) {
        deletedValue = (*head)->data;
        *head = (*head)->next;
        (*head)->prev = NULL;
        return deletedValue;
    }

    Node* curr = *head;
    for (int i = 0; i < index && curr != NULL; i++)
        curr = curr->next;
    if (curr != NULL) {
        deletedValue = curr->data;
        curr->prev->next = curr->next;
        if (curr->next != NULL)
            curr->next->prev = curr->prev;
    }
    return deletedValue;
}

void reverse(Node** head) {
    Node* curr = *head;
    Node* temp = NULL;
    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
        *head = temp->prev;
}

int main() {
    // Creating a linked list
    Node* head = NULL;
    Node* node1 = createNode(11);
    head = node1;
    Node* node2 = createNode(18);
    node1->next = node2;
    node2->prev = node1;
    Node* node3 = createNode(24);
    node2->next = node3;
    node3->prev = node2;

    // Creating new nodes
    Node* newNode1 = createNode(22);
    Node* newNode2 = createNode(43);
    Node* newNode3 = createNode(5);

    // Printing the linked list
    printf("Original linked list: ");
    display(head);

    // Appending new nodes
    append(&head, newNode1);
    append(&head, newNode2);
    append(&head, newNode3);
    printf("Linked list after appending new nodes: ");
    display(head);

    // Inserting a new node at index 2
    Node* newNode4 = createNode(33);
    insert(&head, newNode4, 2);
    printf("Linked list after inserting a new node at index 2: ");
    display(head);

    // Deleting a node at index 3
    int deletedValue = deleteNode(&head, 3);
    printf("Linked list after deleting a node at index 3: ");
    display(head);
    printf("Deleted value: %d\n", deletedValue);

    // Reversing the linked list
    reverse(&head);
    printf("Linked list after reversing: ");
    display(head);

    return 0;
}