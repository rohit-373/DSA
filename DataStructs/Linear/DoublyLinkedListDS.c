#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

typedef struct linkedlist {
    Node* head;
} LinkedList;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

LinkedList* createLinkedList() {
    LinkedList* l = (LinkedList*)malloc(sizeof(LinkedList));
    l->head = NULL;
    return l;
}

void display(LinkedList* l) {
    Node* curr = l->head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("null\n");
}

void append(LinkedList* l, Node* newNode) {
    if (l->head == NULL) {
        l->head = newNode;
    } else {
        Node* curr = l->head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = newNode;
        newNode->prev = curr;
    }
}

void insert(LinkedList* l, Node* newNode, int index) {
    if (index == 0) {
        newNode->next = l->head;
        l->head->prev = newNode;
        l->head = newNode;
    } else {
        Node* curr = l->head;
        for (int i = 0; i < index-1 && curr->next != NULL; i++)
            curr = curr->next;
        if (curr->next != NULL) {
            newNode->next = curr->next;
            curr->next = newNode;
            newNode->prev = curr;
            newNode->next->prev = newNode;
        }
    }
}

int deleteNode(LinkedList* l, int index) {
    int deletedValue = -1;
    if (index == 0) {
        Node* temp = l->head;
        deletedValue = temp->data;
        l->head = l->head->next;
        l->head->prev = NULL;
        free(temp);
    } else {
        Node* curr = l->head;
        for (int i = 0; i < index && curr != NULL; i++)
            curr = curr->next;
        if (curr != NULL) {
            deletedValue = curr->data;
            curr->prev->next = curr->next;
            if (curr->next != NULL)
                curr->next->prev = curr->prev;
            free(curr);
        }
    }
    return deletedValue;
}

void reverse(LinkedList* l) {
    Node* temp = NULL;
    Node* curr = l->head;
    while (curr != NULL) {
        temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = temp;
    }
    if (temp != NULL) {
        l->head = temp->prev;
    }
}

int main() {
    // Creating a linked list
    LinkedList* l1 = createLinkedList();
    Node* node1 = createNode(11);
    l1->head = node1;
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
    display(l1);

    // Appending new nodes
    append(l1, newNode1);
    append(l1, newNode2);
    append(l1, newNode3);
    printf("Linked list after appending new nodes: ");
    display(l1);

    // Inserting a new node at index 2
    Node* newNode4 = createNode(33);
    insert(l1, newNode4, 2);
    printf("Linked list after inserting a new node at index 2: ");
    display(l1);

    // Deleting a node at index 3
    int deletedValue = deleteNode(l1, 3);
    printf("Linked list after deleting a node at index 3: ");
    display(l1);
    printf("Deleted value: %d\n", deletedValue);

    // Reversing the linked list
    reverse(l1);
    printf("Linked list after reversing: ");
    display(l1);

    return 0;
}