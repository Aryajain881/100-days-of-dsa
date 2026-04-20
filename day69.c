#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX

struct Node {
    int dest, weight;
    struct Node* next;
};

struct HeapNode {
    int v, dist;
};

struct MinHeap {
    int size, capacity;
    int *pos;
    struct HeapNode **array;
};

void dijkstra(int V, struct Node* adj[], int src) {
    int dist[V];
    struct MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INF;
        minHeap->array[v] = newHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
    minHeap->size = V;

    while (!isEmpty(minHeap)) {
        struct HeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->dest;
            if (isInMinHeap(minHeap, v) && dist[u] != INF && 
                temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            temp = temp->next;
        }
    }
}
