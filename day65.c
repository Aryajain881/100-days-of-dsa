#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int adj[MAX][MAX];
int adjSize[MAX];
int visited[MAX];

int dfs(int node, int parent) {
    visited[node] = 1;

    for(int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if(!visited[neighbor]) {
            if(dfs(neighbor, node))
                return 1;
        }
        else if(neighbor != parent) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    for(int i = 0; i < V; i++) {
        adjSize[i] = 0;
        visited[i] = 0;
    }

    for(int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][adjSize[u]++] = v;
        adj[v][adjSize[v]++] = u;
    }

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}