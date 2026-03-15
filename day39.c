#include <stdio.h>
#include <string.h>

int heap[1000];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int i) {
    while(i > 0) {
        int parent = (i - 1) / 2;
        if(heap[parent] <= heap[i])
            break;
        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

void heapifyDown(int i) {
    while(1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

void insert(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

int peek() {
    if(size == 0)
        return -1;
    return heap[0];
}

int extractMin() {
    if(size == 0)
        return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
    return min;
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
        else if(strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        }
    }

    return 0;
}