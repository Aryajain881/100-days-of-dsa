#include <stdio.h>
#define MAX 100

// Queue
int queue[MAX];
int front = -1, rear = -1;

// Stack
int stack[MAX];
int top = -1;

// Queue operations
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// Stack operations
void push(int x) {
    if (top == MAX - 1) return;
    stack[++top] = x;
}

int pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Reverse queue using stack
void reverseQueue() {
    // Step 1: Move queue → stack
    while (front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Move stack → queue
    while (top != -1) {
        enqueue(pop());
    }
}

// Print queue
void display() {
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main() {
    int n, x;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    reverseQueue();

    display();

    return 0;
}