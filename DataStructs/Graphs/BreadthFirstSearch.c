#include <stdio.h>

void BFS(int n, int graph[n][n], int start) {
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int queue[n];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);
    n++; // 1-based indexing
    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    BFS(n, graph, 5);
    return 0;
}