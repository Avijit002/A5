#include <stdio.h>

int adj[20][20], parent[20];
int V, E;

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);

    if (a != b)
        parent[a] = b;
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
        parent[i] = i;

    for (i = 0; i < V; i++) {
        for (j = i + 1; j < V; j++) {
            if (adj[i][j] == 1)
                unionSets(i, j);
        }
    }

    for (i = 0; i < V; i++) {
        if (parent[i] == i)
            count++;
    }

    printf("Connected Components using Union-Find: %d\n", count);

    return 0;
}
