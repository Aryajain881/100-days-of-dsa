#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 1005

typedef struct {
    int node;
    int weight;
} Pair;

typedef struct {
    Pair data[MAX * MAX];
    int size;
} MinHeap;

void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *heap, int node, int weight) {
    int i = heap->size++;
    heap->data[i].node = node;
    heap->data[i].weight = weight;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->data[parent].weight <= heap->data[i].weight)
            break;
        swap(&heap->data[parent], &heap->data[i]);
        i = parent;
    }
}

Pair pop(MinHeap *heap) {
    Pair top = heap->data[0];
    heap->data[0] = heap->data[--heap->size];

    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap->size && heap->data[left].weight < heap->data[smallest].weight)
            smallest = left;
        if (right < heap->size && heap->data[right].weight < heap->data[smallest].weight)
            smallest = right;

        if (smallest == i) break;

        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }

    return top;
}

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

Node* adj[MAX];
bool visited[MAX];

void addEdge(int u, int v, int w) {
    Node* n1 = (Node*)malloc(sizeof(Node));
    n1->v = v; n1->w = w; n1->next = adj[u];
    adj[u] = n1;

    Node* n2 = (Node*)malloc(sizeof(Node));
    n2->v = u; n2->w = w; n2->next = adj[v];
    adj[v] = n2;
}

int prim(int n) {
    MinHeap heap = {.size = 0};
    push(&heap, 1, 0); // start from node 1

    int total = 0;

    while (heap.size > 0) {
        Pair p = pop(&heap);
        int u = p.node;
        int w = p.weight;

        if (visited[u]) continue;

        visited[u] = true;
        total += w;

        Node* temp = adj[u];
        while (temp) {
            if (!visited[temp->v]) {
                push(&heap, temp->v, temp->w);
            }
            temp = temp->next;
        }
    }

    return total;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    printf("%d\n", prim(n));
    return 0;
}