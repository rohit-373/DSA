#include <stdio.h>

void Prims(int n, int graph[n][n], int start) {
    int visited[n], parent[n], key[n];
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
        key[i] = 9999;
    }

    key[start] = 0;
    for(int i = 0; i < n; i++) {
        int min = 9999, u;
        for(int j = 0; j < n; j++) {
            if(visited[j] == 0 && key[j] < min) {
                min = key[j];
                u = j;
            }
        }

        visited[u] = 1;
        for(int v = 0; v < n; v++) {
            if(graph[u][v] != 0 && visited[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if (parent[i] != -1)
            printf("%d-%d %d\n", parent[i], i, key[i]);
    }
}

int main() {
    int n, e, start;
    scanf("%d %d", &n, &e);
    n++;

    // Adjacency matrix
    int graph[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Edge list
    for(int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    // Start vertex
    scanf("%d", &start);

    Prims(n, graph, start);
    return 0;
}