#include <stdio.h>

int adj[20][20], visited[20], q[20], parent[20];
int V, E;

// BFS Helper 
void bfs(int start) {
    int r = -1, f = 0, cur, i;
    
    // Enqueue
    r++; q[r] = start;
    visited[start] = 1;
    
    while(f <= r) {
        cur = q[f]; f++; // Dequeue
        
        for(i = 0; i < V; i++) {
            if(adj[cur][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                r++; q[r] = i;
            }
        }
    }
}

// (No BFS/DFS)  Union-Find Helpers 
int find(int i) {
    while(parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    if(a != b) parent[a] = b;
}

int main() {
    int i, j, u, v, count;
    
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
    
    // A: Count using BFS 
    for(i=0; i<V; i++) visited[i] = 0;
    count = 0;
    
    for(i=0; i<V; i++) {
        if(visited[i] == 0) {
            count++; 
            bfs(i);  
        }
    }
    printf("\n(a) Connected Components (using BFS): %d\n", count);
    
    //  B: Count using Union-Find (No BFS/DFS) 
    for(i=0; i<V; i++) parent[i] = i; 
    
    // Process all edges
    for(i=0; i<V; i++) {
        for(j=i+1; j<V; j++) {
            if(adj[i][j] == 1) {
                unionSets(i, j);
            }
        }
    }
    
    count = 0;
    for(i=0; i<V; i++) {
        if(parent[i] == i) count++;
    }
    printf("(b) Connected Components (using No BFS/DFS): %d\n", count);
    
    return 0;
}
