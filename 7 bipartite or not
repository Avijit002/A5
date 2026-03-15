#include <stdio.h>

int adj[20][20], color[20], q[20], f = 0, r = -1;
int V, E;

int isBipartite() {
    int i, u, v;
    
    // Initialize colors to -1 (No color)
    for(i=0; i<V; i++) color[i] = -1;
    
    // Check for all components
    for(i=0; i<V; i++) {
        if(color[i] == -1) {
            
            // Start BFS from node i
            r++; q[r] = i; 
            color[i] = 1; // Assign first color
            
            while(f <= r) {
                u = q[f]; f++; // Dequeue
                
                // Check neighbors
                for(v=0; v<V; v++) {
                    if(adj[u][v] == 1) {
                        
                        // If neighbor uncolored, assign opposite color
                        if(color[v] == -1) {
                            color[v] = 1 - color[u];
                            r++; q[r] = v;
                        }
                        
                        // If neighbor has same color, NOT Bipartite
                        else if(color[v] == color[u]) {
                            return 0; 
                        }
                    }
                }
            }
        }
    }
    return 1; // True
}

int main() {
    int i, j, u, v;
    
    printf("Enter number of Vertices: ");
    scanf("%d", &V);
    printf("Enter number of Edges: ");
    scanf("%d", &E);
    
    // Init Graph
    for(i=0; i<V; i++) for(j=0; j<V; j++) adj[i][j] = 0;
    
    printf("Enter %d edges (u v):\n", E);
    for(i=0; i<E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    if(isBipartite()) {
        printf("\nResult: Graph is Bipartite.\n");
    } else {
        printf("\nResult: Graph is NOT Bipartite.\n");
    }
    
    return 0;
}
