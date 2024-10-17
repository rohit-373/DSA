#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(Node* head) {
    Node* curr = head;
    while (curr->next != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("%d\n", curr->data);
}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
}

void insert(Node** head, int data, int index) {
    Node* newNode = createNode(data);
    if (index == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* curr = *head;
    for (int i = 0; i < index-1 && curr->next != NULL; i++) {
        curr = curr->next;
    }
    if (curr->next != NULL) {
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

int delete(Node** head, int index) {
    int deletedValue = -1;
    if (index == 0) {
        deletedValue = (*head)->data;
        *head = (*head)->next;
        return deletedValue;
    }

    Node* curr = *head;
    Node* prev = NULL;
    for (int i = 0; i < index && curr != NULL; i++) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        deletedValue = curr->data;
        prev->next = curr->next;
        free(curr);
    }
    return deletedValue;
}

void reverse(Node** head) {
    Node* prev = NULL;
    Node* curr = *head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main() {
    // Creating a linked list
    Node* head = NULL;
    Node* node1 = createNode(11);
    head = node1;
    Node* node2 = createNode(18);
    node1->next = node2;
    Node* node3 = createNode(24);
    node2->next = node3;

    // Printing the linked list
    printf("Original linked list: ");
    display(head);

    // Appending new nodes
    append(&head, 22);
    printf("Linked list after appending: ");
    display(head);
    
    // Inserting new nodes
    insert(&head, 43, 0);
    insert(&head, 5, 2);
    printf("Linked list after inserting: ");
    display(head);

    // Removing a node
    int deletedValue = delete(&head, 2);
    printf("Linked list after removing: ");
    display(head);
    printf("Deleted value: %d\n", deletedValue);

    // Reversing the linked list
    reverse(&head);
    printf("Linked list after reversing: ");
    display(head);

    return 0;
}