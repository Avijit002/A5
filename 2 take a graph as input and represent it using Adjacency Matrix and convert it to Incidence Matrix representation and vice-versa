#include <stdio.h>

int adj[20][20], inc[20][50];
int V = 0, E = 0;

void displayAdj() {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

void displayInc() {
    int i, j;
    printf("\nIncidence Matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < E; j++) {
            printf("%d ", inc[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j, u, v, k;

    // Input
    printf("Enter number of Vertices: ");
    scanf("%d", &V);
    printf("Enter number of Edges: ");
    scanf("%d", &E);

    // Init Adj
    for(i=0; i<V; i++) for(j=0; j<V; j++) adj[i][j] = 0;
    
    printf("Enter %d edges (u v):\n", E);
    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    // Adj -> Inc
    for(i=0; i<V; i++) for(j=0; j<E; j++) inc[i][j] = 0;

    k = 0;
    for (i = 0; i < V; i++) {
        for (j = i; j < V; j++) {
             if (adj[i][j] == 1 && k < E) {
                 inc[i][k] = 1;
                 inc[j][k] = 1;
                 k++;
             }
        }
    }

    displayAdj();
    displayInc();

    // Inc -> Adj
    for(i=0; i<V; i++) for(j=0; j<V; j++) adj[i][j] = 0;

    for (k = 0; k < E; k++) {
        int u = -1, v = -1;
        for (i = 0; i < V; i++) {
            if (inc[i][k] == 1) {
                if (u == -1) u = i;
                else v = i;
            }
        }
        if (u != -1 && v != -1) {
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }

    printf("\nConverted back to Adjacency Matrix :\n");
    displayAdj();

    return 0;
}
