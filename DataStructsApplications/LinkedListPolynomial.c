#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff, power;
    struct Node *next;
} Node;

Node* createNode(int coeff, int power) {
    Node* newNode = malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

void display(Node* head) {
    Node* curr = head;
    while (curr->next != NULL) {
        printf("%dx^%d + ", curr->coeff, curr->power);
        curr = curr->next;
    }
    printf("%dx^%d\n", curr->coeff, curr->power);
}

void insertNode(Node** head, int coeff, int power) {
    if (coeff == 0)
        return;

    Node* newNode = createNode(coeff, power);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while (curr->next != NULL) {
        if (curr->power == power) {
            curr->coeff += coeff;
            return;
        }
        curr = curr->next;
    }
    if (curr->power == power) {
        curr->coeff += coeff;
    } else {
        curr->next = newNode;
    }
}

void addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* curr1 = poly1;
    Node* curr2 = poly2;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->power == curr2->power) {
            insertNode(&result, curr1->coeff + curr2->coeff, curr1->power);
            curr1 = curr1->next;
            curr2 = curr2->next;
        } else if (curr1->power > curr2->power) {
            insertNode(&result, curr1->coeff, curr1->power);
            curr1 = curr1->next;
        } else {
            insertNode(&result, curr2->coeff, curr2->power);
            curr2 = curr2->next;
        }
    }

    while (curr1 != NULL) {
        insertNode(&result, curr1->coeff, curr1->power);
        curr1 = curr1->next;
    }

    while (curr2 != NULL) {
        insertNode(&result, curr2->coeff, curr2->power);
        curr2 = curr2->next;
    }

    display(result);
}

void multiplyPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* curr1 = poly1;
    Node* curr2 = poly2;

    while (curr1 != NULL) {
        curr2 = poly2;
        while (curr2 != NULL) {
            insertNode(&result, curr1->coeff * curr2->coeff, curr1->power + curr2->power);
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }

    display(result);
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    insertNode(&poly1, 5, 2);
    insertNode(&poly1, 4, 1);
    insertNode(&poly1, 2, 0);

    insertNode(&poly2, 3, 2);
    insertNode(&poly2, 1, 1);
    insertNode(&poly2, 2, 0);

    printf("Polynomial 1:\n");
    display(poly1);
    printf("Polynomial 2:\n");
    display(poly2);
    printf("Addition:\n");
    addPolynomials(poly1, poly2);
    printf("Multiplication:\n");
    multiplyPolynomials(poly1, poly2);
    return 0;
}