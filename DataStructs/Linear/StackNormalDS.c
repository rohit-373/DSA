#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct stk {
    int top, arr[MAX_SIZE];
} Stack;

Stack* createStack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int item) {
    if (isFull(s))
        return;
    s->arr[++s->top] = item;
}

int pop(Stack *s) {
    if (isEmpty(s))
        return -1;
    return s->arr[s->top--];
}

int peek(Stack *s) {
    if (isEmpty(s))
        return -1;
    return s->arr[s->top];
}

int main() {
    Stack *s = createStack();

    printf("Item at top of stack is %d\n", peek(s));
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printf("%d popped from stack\n", pop(s));
    printf("%d popped from stack\n", pop(s));
    printf("Item at top of stack is %d\n", peek(s));

    return 0;
}