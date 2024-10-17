#include <stdio.h>

void Kruskal(int n, int e, int edges[3][e]) {
    int parent[n];
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[2][j] > edges[2][j + 1]) {
                int temp = edges[2][j];
                edges[2][j] = edges[2][j + 1];
                edges[2][j + 1] = temp;

                temp = edges[0][j];
                edges[0][j] = edges[0][j + 1];
                edges[0][j + 1] = temp;

                temp = edges[1][j];
                edges[1][j] = edges[1][j + 1];
                edges[1][j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < e; i++) {
        int u = edges[0][i];
        int v = edges[1][i];
        int w = edges[2][i];

        while(parent[u] != u) {
            u = parent[u];
        }

        while(parent[v] != v) {
            v = parent[v];
        }

        if(u != v) {
            printf("%d-%d %d\n", edges[0][i], edges[1][i], edges[2][i]);
            parent[v] = u;
        }
    }
}

int main() {
    int n, e;
    scanf("%d %d", &n, &e);
    n++;

    int edges[3][e];
    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[0][i], &edges[1][i], &edges[2][i]);
    }

    Kruskal(n, e, edges);
    return 0;
}