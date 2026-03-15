#include <stdio.h>

int adj[20][20], visited[20];
int V, E;

void dfs(int cur) {
    int i; 
    
    // current node
    printf("%d ", cur);
    
    // Mark as visited
    visited[cur] = 1;
    
    // Visit neighbors
    for(i = 0; i < V; i++) {
        // If neighbor exists and not visited
        if(adj[cur][i] == 1 && visited[i] == 0) {
            dfs(i); 
        }
    }
}

int main() {
    int i, j, u, v, start;
    
    printf("Enter number of Vertices: ");
    scanf("%d", &V);
    
    printf("Enter number of Edges: ");
    scanf("%d", &E);
    
    // Initialize Arrays
    for(i=0; i<V; i++) {
        visited[i] = 0;
        for(j=0; j<V; j++) adj[i][j] = 0;
    }
    
    printf("Enter %d edges (u v):\n", E);
    for(i=0; i<E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    printf("Enter Starting Vertex: ");
    scanf("%d", &start);
    
    printf("\nDFS Traversal: ");
    dfs(start);
    printf("\n");
    
    return 0;
}
