#include <stdio.h>

void DFS(int n, int graph[n][n], int visited[n], int start) {
    visited[start] = 1;
    printf("%d ", start);
    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && visited[i] == 0)
            DFS(n, graph, visited, i);
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

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    DFS(n, graph, visited, 5);
    return 0;
}