#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

void push_front(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if(dq->front != NULL)
        dq->front->prev = newNode;
    else
        dq->rear = newNode;

    dq->front = newNode;
    dq->size++;
}

void push_back(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if(dq->rear != NULL)
        dq->rear->next = newNode;
    else
        dq->front = newNode;

    dq->rear = newNode;
    dq->size++;
}

void pop_front(Deque* dq) {
    if(dq->front == NULL) return;

    Node* temp = dq->front;
    dq->front = dq->front->next;

    if(dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
}

void pop_back(Deque* dq) {
    if(dq->rear == NULL) return;

    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if(dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
}

int front(Deque* dq) {
    if(dq->front == NULL) return -1;
    return dq->front->data;
}

int back(Deque* dq) {
    if(dq->rear == NULL) return -1;
    return dq->rear->data;
}

int empty(Deque* dq) {
    return dq->size == 0;
}

int size(Deque* dq) {
    return dq->size;
}

void clear(Deque* dq) {
    while(!empty(dq))
        pop_front(dq);
}

void display(Deque* dq) {
    Node* temp = dq->front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Deque* dq = createDeque();

    push_back(dq, 10);
    push_back(dq, 20);
    push_front(dq, 5);
    push_back(dq, 30);

    printf("Deque elements: ");
    display(dq);

    printf("Front: %d\n", front(dq));
    printf("Back: %d\n", back(dq));
    printf("Size: %d\n", size(dq));

    pop_front(dq);
    pop_back(dq);

    printf("After pop operations: ");
    display(dq);

    clear(dq);
    printf("Deque empty? %d\n", empty(dq));

    return 0;
}