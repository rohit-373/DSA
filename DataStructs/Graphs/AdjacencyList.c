#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data, weight;
    struct Node *next;
} Node;

Node* createNode(int data, int weight) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int data, int weight) {
    Node* newNode = createNode(data, weight);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void BFS(Node** graph, int n, int start) {
    int *visited = (int *)calloc(n, sizeof(int));
    Node **queue = (Node **)malloc(n * sizeof(Node *));
    int front = 0, rear = 0;
    queue[rear++] = graph[start];
    visited[start] = 1;
    while (front < rear) {
        Node* curr = queue[front++];
        printf("%d ", curr->data);
        for (; curr != NULL; curr = curr->next) {
            if (visited[curr->data] == 0) {
                queue[rear++] = graph[curr->data];
                visited[curr->data] = 1;
            }
        }
    }
}

void DFS(Node** graph, int n, int *visited, int start) {
    visited[start] = 1;
    printf("%d ", start);
    for (Node* curr = graph[start]; curr != NULL; curr = curr->next) {
        if (visited[curr->data] == 0)
            DFS(graph, n, visited, curr->data);
    }
}

int main() {
    int n, e, w = 1;
    scanf("%d %d", &n, &e);
    n++; // 1-based indexing
    Node** graph = (Node **)calloc(n, sizeof(Node *));
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        append(&graph[u], v, w);
        append(&graph[v], u, w); // For undirected graph
    }

    int *visited = (int *)calloc(n, sizeof(int));
    DFS(graph, n, visited, 1);
    return 0;
}