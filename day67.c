#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int adj[MAX][MAX];
int adjSize[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int node) {
    visited[node] = 1;
    for (int i=0; i<adjSize[node]; i++)
    { int neighbor = adj[node][i];
      if(!visited[neighbor])
      { dfs(neighbor); }
    }
    stack[++top] = node;
}

int main() {
    int V, E;
    if(scanf("%d %d", &V, &E) != 2)
    { return 0; }
    for(int i=0; i<V; i++)
    { adjSize[i] = 0;
      visited[i] = 0; }
    
    for (int i=0; i<E; i++)
    { int u, v;
      scanf("%d %d", &u, &v);
      adj[u][adjSize[u]++] = v; }

    for(int i=0; i<V; i++)
    { if(!visited[i])
      { dfs(i); }
    }
    printf("Topological Sort: ");
    while(top >= 0)
    { printf("%d ", stack[top--]); }
    return 0;
}
