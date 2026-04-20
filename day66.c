#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

int adj[MAX][MAX];
int adjSize[MAX];
int visited[MAX];
int recStack[MAX];

int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for(int i=0; i<adjSize[node]; i++)
    { int neighbor = adj[node][i];
      if(!visited[neighbor])
      { if(dfs(neighbor))
        { return 1; } 
      }
      else if(recStack[neighbor])
      { return 1; }
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    for(int i=0; i<V; i++)
    { adjSize[i] = 0;
      visited[i] = 0;
      recStack[i] = 0;
    }

    for(int i=0; i<E; i++)
    { int u, v;
      scanf("%d %d", &u, &v);
      adj[u][adjSize[u]++] = v;
    }

    for(int i=0; i<V; i++)
    { if(!visited[i])
      { if(dfs(i))
        { printf("YES");
          return 0;
        }
      }
    }
    printf("NO");
    return 0;
}