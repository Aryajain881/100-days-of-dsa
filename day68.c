#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100 // Maximum number of vertices

// Structure to represent a node in the adjacency list
struct Node {
    int dest;
    struct Node* next;
};

// Structure for the graph
struct Graph {
    int V;
    struct Node* adj[MAX_V];
};

// Simple Queue structure for C
struct Queue {
    int items[MAX_V];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(struct Queue* q, int value) {
    q->items[++(q->rear)] = value;
}

int dequeue(struct Queue* q) {
    return q->items[(q->front)++];
}

int isQueueEmpty(struct Queue* q) {
    return q->front > q->rear;
}

void topologicalSort(struct Graph* graph) {
    int inDegree[MAX_V] = {0};
    int result[MAX_V];
    int count = 0;
    struct Queue q;
    initQueue(&q);

    // 1. Calculate in-degrees
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adj[i];
        while (temp) {
            inDegree[temp->dest]++;
            temp = temp->next;
        }
    }

    // 2. Push all nodes with 0 in-degree to the queue
    for (int i = 0; i < graph->V; i++) {
        if (inDegree[i] == 0) {
            enqueue(&q, i);
        }
    }

    // 3. Process the queue
    while (!isQueueEmpty(&q)) {
        int u = dequeue(&q);
        result[count++] = u;

        struct Node* temp = graph->adj[u];
        while (temp) {
            int v = temp->dest;
            inDegree[v]--;
            if (inDegree[v] == 0) {
                enqueue(&q, v);
            }
            temp = temp->next;
        }
    }

    // Check for cycles
    if (count != graph->V) {
        printf("The graph has a cycle. Topological sort not possible.\n");
    } else {
        printf("Topological Sort: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
}
