#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct linkedlist{
    Node* head;
} LinkedList;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

LinkedList* createLinkedList() {
    LinkedList* l = (LinkedList*)malloc(sizeof(LinkedList));
    l->head = NULL;
    return l;
}

void print(LinkedList* l) {
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
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void insert(LinkedList* l, Node* newNode, int index) {
    if (index == 0) {
        newNode->next = l->head;
        l->head = newNode;
    } else {
        Node* curr = l->head;
        for (int i = 0; i < index-1 && curr != NULL; i++) {
            curr = curr->next;
        }
        if (curr != NULL) {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
}

int delete(LinkedList* l, int index) {
    int deletedValue = -1;
    if (index == 0) {
        Node* temp = l->head;
        deletedValue = temp->data;
        l->head = l->head->next;
        free(temp);
    } else {
        Node* curr = l->head;
        Node* prev = NULL;
        for (int i = 0; i < index && curr != NULL; i++) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL) {
            Node* temp = curr;
            deletedValue = temp->data;
            prev->next = curr->next;
            free(temp);
        }
    }
    return deletedValue;
}

void reverse(LinkedList* l) {
    Node* prev = NULL;
    Node* curr = l->head;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l->head = prev;
}

int main() {
    // Creating a linked list
    LinkedList* l1 = createLinkedList();
    Node* node1 = createNode(11);
    l1->head = node1;
    Node* node2 = createNode(18);
    node1->next = node2;
    Node* node3 = createNode(24);
    node2->next = node3;

    // Creating new nodes
    Node* newNode1 = createNode(22);
    Node* newNode2 = createNode(43);
    Node* newNode3 = createNode(5);

    // Printing the linked list
    printf("Original linked list: ");
    print(l1);

    // Appending new nodes
    append(l1, newNode1);
    printf("Linked list after appending: ");
    print(l1);
    
    // Inserting new nodes
    insert(l1, newNode2, 0);
    insert(l1, newNode3, 2);
    printf("Linked list after inserting: ");
    print(l1);

    // Removing a node
    int deletedValue = delete(l1, 2);
    printf("Linked list after removing: ");
    print(l1);
    printf("Deleted value: %d\n", deletedValue);

    // Reversing the linked list
    reverse(l1);
    printf("Linked list after reversing: ");
    print(l1);

    return 0;
}