#include <stdio.h>

int adj[20][20], visited[20], q[20], f = 0, r = -1;
int V, E;

void bfs(int start) {
    int i, cur;
    
    // Enqueue start vertex
    r++;
    q[r] = start;
    visited[start] = 1;
    
    printf("\nBFS Traversal: ");
    
    while(f <= r) {
        // Dequeue
        cur = q[f];
        f++;
        printf("%d ", cur);
        
        // Visit neighbors
        for(i = 0; i < V; i++) {
            if(adj[cur][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                r++;
                q[r] = i;
            }
        }
    }
    printf("\n");
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
    
    bfs(start);
    
    return 0;
}
