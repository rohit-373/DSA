#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct stk {
    Node *top;
} Stack;

Stack* createStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

int isEmpty(Stack *s) {
    return (s->top == NULL);
}

void push(Stack *s, int item) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s) {
    if (isEmpty(s))
        return -1;
    Node *temp = s->top;
    s->top = s->top->next;
    int element = temp->data;
    free(temp);
    return element;
}

int peek(Stack *s) {
    if (isEmpty(s))
        return -1;
    return s->top->data;
}

int main() {
    Stack *s = createStack();

    printf("Item at top of stack is %d\n", peek(s));
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    printf("%d popped from stack\n", pop(s));
    printf("%d popped from stack\n", pop(s));
    printf("Item at top of stack is %d\n", peek(s));

    return 0;
}