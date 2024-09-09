#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct q {
    Node *front, *rear;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enQueue(Queue *q, int item) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    if (isEmpty(q))
        q->front = newNode;
    else
        q->rear->next = newNode;
    q->rear = newNode;
}

int deQueue(Queue *q) {
    if (isEmpty(q))
        return -1;
    Node *temp = q->front;
    q->front = q->front->next;
    int element = temp->data;
    free(temp);
    return element;
}

int getFront(Queue *q) {
    if (isEmpty(q))
        return -1;
    return q->front->data;
}

int getRear(Queue *q) {
    if (isEmpty(q))
        return -1;
    return q->rear->data;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue *q = createQueue();

    printf("Item at front of queue is %d\n", getFront(q));
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);
    display(q);
    printf("%d dequeued from queue\n", deQueue(q));
    printf("%d dequeued from queue\n", deQueue(q));
    printf("Item at front of queue is %d\n", getFront(q));

    return 0;
}