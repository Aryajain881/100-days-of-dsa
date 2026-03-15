#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int *queue = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    scanf("%d", &m);

    int front = 0;
    int rear = n - 1;

    for(int i = 0; i < m; i++) {
        front = (front + 1) % n;
        rear = (rear + 1) % n;
    }

    int count = n;
    int index = front;

    for(int i = 0; i < count; i++) {
        printf("%d ", queue[index]);
        index = (index + 1) % n;
    }

    free(queue);
    return 0;
}