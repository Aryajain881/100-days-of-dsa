#include<stdio.h>
#include<stdlib.h>
void dfs(int u, int n, int adj[n+1][n+1], int *visited) {
    visited[u] = 1;
    for(int v=1; v<=n; v++)
    {  if(adj[u][v] && !visited[v])
        { dfs(v, n, adj, visited); }
    }
}
int main()
{
    int n, m;
    if(scanf("%d %d", &n, &m) != 2)
    { return 0; }
    if(n == 0)
    {  printf("CONNECTED\n");
       return 0;
    }
    
    int adj[n+1][n+1], i, j;
    for(i=0; i<=n; i++)
    { for(j=0; j<=n; j++)
      { adj[i][j] = 0; }
    }
    for(i=0; i<m; i++)
    { int u, v;
      scanf("%d %d", &u, &v);
      adj[u][v] = 1;
      adj[v][u] = 1;
    }
    int visited[n+1], count=0;
    for (int i = 0; i <= n; i++)
    { visited[i] = 0; }
    dfs(1, n, adj, visited);
    
    for(i=1; i<=n; i++)
    { if(visited[i])
      { count++; }
    }
    if(count == n)
    { printf("CONNECTED\n"); }
    else
    { printf("NOT CONNECTED\n"); }
    return 0;
}