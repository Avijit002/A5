#include <stdio.h>

int adj[20][20], visited[20], q[20];
int V, E;

void bfs(int start) {
    int r = -1, f = 0, cur, i;

    r++;
    q[r] = start;
    visited[start] = 1;

    while (f <= r) {
        cur = q[f];
        f++;

        for (i = 0; i < V; i++) {
            if (adj[cur][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                r++;
                q[r] = i;
            }
        }
    }
}

int main() {

    int i, j, u, v, count = 0;

    printf("Enter number of Vertices: ");
    scanf("%d", &V);

    printf("Enter number of Edges: ");
    scanf("%d", &E);

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for (i = 0; i < V; i++)
        visited[i] = 0;

    for (i = 0; i < V; i++) {
        if (visited[i] == 0) {
            count++;
            bfs(i);
        }
    }

    printf("Connected Components using BFS: %d\n", count);

    return 0;
}
