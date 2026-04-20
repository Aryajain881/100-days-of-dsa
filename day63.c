#include <stdio.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

void dfs(int current, struct Node** adjList, bool* visited) {
    visited[current] = true;
    printf("%d ", current);
    struct Node* temp = adjList[current];
    while (temp != NULL) {
        int neighbor = temp->vertex;
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
        temp = temp->next;
    }
}