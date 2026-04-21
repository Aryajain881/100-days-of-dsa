#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1005

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];

// Min Heap
typedef struct {
    int node, dist;
} Pair;

typedef struct {
    Pair heap[MAX * MAX];
    int size;
} MinHeap;

void swap(Pair *a, Pair *b) {
    Pair t = *a; *a = *b; *b = t;
}

void push(MinHeap* h, int node, int dist) {
    int i = h->size++;
    h->heap[i].node = node;
    h->heap[i].dist = dist;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->heap[p].dist <= h->heap[i].dist) break;
        swap(&h->heap[p], &h->heap[i]);
        i = p;
    }
}

Pair pop(MinHeap* h) {
    Pair top = h->heap[0];
    h->heap[0] = h->heap[--h->size];

    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, s = i;

        if (l < h->size && h->heap[l].dist < h->heap[s].dist) s = l;
        if (r < h->size && h->heap[r].dist < h->heap[s].dist) s = r;
        if (s == i) break;

        swap(&h->heap[i], &h->heap[s]);
        i = s;
    }

    return top;
}

void addEdge(int u, int v, int w) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->v = v;
    n->w = w;
    n->next = adj[u];
    adj[u] = n;
}

void dijkstra(int n, int src) {
    int dist[MAX];
    bool visited[MAX] = {false};

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    MinHeap h = {.size = 0};

    dist[src] = 0;
    push(&h, src, 0);

    while (h.size > 0) {
        Pair p = pop(&h);
        int u = p.node;

        if (visited[u]) continue;
        visited[u] = true;

        Node* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w); // directed
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}