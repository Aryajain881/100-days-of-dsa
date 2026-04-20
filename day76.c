#include<stdio.h>
#include<stdbool.h>
int adj[100][100], n;
bool visited[100];
void dfs(int v) {
    visited[v] = true;
    for(int i=1; i<=n; i++)
    { if(adj[v][i] == 1 && !visited[i])
      { dfs(i); }
    }
}
int main()
{
    int m, u, v, i, count=0;
    if(scanf("%d %d", &n, &m) != 2) return 0;
    for(int i = 0; i < m; i++)
    { scanf("%d %d", &u, &v);
      adj[u][v] = 1;
      adj[v][u] = 1;
    }
    for(i=1; i<=n; i++)
    { if(!visited[i])
      { count++;
        dfs(i); }
    }
    printf("%d\n", count);
    return 0;
}