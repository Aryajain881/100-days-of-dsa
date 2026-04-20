#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

void bfs(int n, int adj[MAX][MAX], int s) {
    int queue[MAX];
    int front = 0, rear = 0;
    bool visited[MAX] = {false};

    // Push source to queue
    queue[rear++] = s;
    visited[s] = true;

    printf("BFS Traversal: ");

    while (front < rear) {
        // Pop from queue
        int u = queue[front++];
        printf("%d ", u);

        // Visit neighbors
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 5; // Number of nodes
    int adj[MAX][MAX] = {0};

    // Example: Adding edges (Adjacency Matrix)
    adj[0][1] = 1; adj[1][0] = 1;
    adj[0][2] = 1; adj[2][0] = 1;
    adj[1][3] = 1; adj[3][1] = 1;
    adj[2][4] = 1; adj[4][2] = 1;

    bfs(n, adj, 0); // Start BFS from node 0

    return 0;
}
