#include <stdio.h>

int adj[20][20], visited[20];
int V, E;

void dfs(int v) {
    visited[v] = 1;

    for(int i = 0; i < V; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {

    int u, v, i, j, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for(i=0;i<E;i++){
        scanf("%d %d",&u,&v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(i=0;i<V;i++)
        visited[i] = 0;

    for(i=0;i<V;i++){
        if(visited[i] == 0){
            count++;
            dfs(i);
        }
    }

    printf("Connected Components using DFS: %d\n", count);

    return 0;
}
