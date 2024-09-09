#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct deque {
    int arr[MAX_SIZE];
    int front, rear;
} Deque;

Deque* createDeque() {
    Deque* q = (Deque*)malloc(sizeof(Deque));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isFull(Deque* q) {
    return q->front == (q->rear + 1)%MAX_SIZE;
}

int isEmpty(Deque* q) {
    return q->front == -1;
}

void insertFront(Deque* q, int data) {
    if  (isFull(q))
        return;
    
    if  (isEmpty(q)) {              
        // If deque is empty, set front and rear to 0
        q->front = q->rear = 0;   
    } else if (q->front == 0) {     
        // If front is at 0, set it to MAX_SIZE - 1 
        // because it is a circular array
        q->front = MAX_SIZE - 1;
    } else {                        
        // Else decrement front
        q->front--;
    }
    q->arr[q->front] = data;
}

void insertRear(Deque* q, int data) {
    if  (isFull(q))
        return;
    
    if  (isEmpty(q)) {                      
        // If deque is empty, set front and rear to 0
        q->front = 0;
        q->rear = 0;
    } else if (q->rear == MAX_SIZE - 1) {   
        // If rear is at MAX_SIZE - 1, set it to 0 
        // because it is a circular array
        q->rear = 0;
    } else {                                
        // Else increment rear
        q->rear++;
    }
    q->arr[q->rear] = data;
}

int deleteFront(Deque* q) {
    if  (isEmpty(q)) 
        return -1;
    
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        // If only 1 element is in deque, reset the deque 
        // by setting front and rear to -1
        q->front = -1;
        q->rear = -1;
    } else if (q->front == MAX_SIZE - 1) {  
        // If front is at MAX_SIZE - 1, set it to 0 
        // because it is a circular array
        q->front = 0;
    } else {                                
        // Else increment front
        q->front++;
    }
    return data;
}

int deleteRear(Deque* q) {
    if  (isEmpty(q))
        return -1;

    int data = q->arr[q->rear];
    if (q->front == q->rear) {
        // If only 1 element is in deque, reset the deque 
        // by setting front and rear to -1
        q->front = -1;
        q->rear = -1;
    } else if (q->rear == 0) {
        // If rear is at 0, set it to MAX_SIZE - 1 
        // because it is a circular array
        q->rear = MAX_SIZE - 1;
    } else {
        // Else decrement rear
        q->rear--;
    }
    return data;
}

int getFront(Deque* q) {
    if  (isEmpty(q))
        return -1;
    return q->arr[q->front];
}

int getRear(Deque* q) {
    if  (isEmpty(q))
        return -1;
    return q->arr[q->rear];
}

void display(Deque* q) {
    if  (isEmpty(q)) {
        printf("Deque is empty\n");
        return;
    }
    for (int i = q->front; i != q->rear; i = (i + 1)%MAX_SIZE)
        // If front is greater than rear, i=(i+1)%MAX_SIZE will
        // reset the rear to 0 and continue printing
        printf("%d ", q->arr[i]);
    printf("%d\n", q->arr[q->rear]);
}

int main() {
    Deque* q = createDeque();
    insertFront(q, 1);
    insertFront(q, 2);
    insertRear(q, 3);
    insertRear(q, 4);
    display(q);
    printf("Front: %d\n", getFront(q));
    printf("Rear: %d\n", getRear(q));
    printf("Deleted front: %d\n", deleteFront(q));
    printf("Deleted rear: %d\n", deleteRear(q));
    display(q);
    return 0;
}