#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;
    return q->arr[q->front++];
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;

    struct Queue q;
    initQueue(&q);

    struct Node* root = newNode(arr[0]);
    enqueue(&q, root);

    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue(&q);

        if (i < n) {
            curr->left = newNode(arr[i++]);
            enqueue(&q, curr->left);
        }

        if (i < n) {
            curr->right = newNode(arr[i++]);
            enqueue(&q, curr->right);
        }
    }
    return root;
}

int countNodes(struct Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int isComplete(struct Node* root, int index, int totalNodes) {
    if (!root) return 1;
    if (index >= totalNodes) return 0;

    return isComplete(root->left, 2*index + 1, totalNodes) &&
           isComplete(root->right, 2*index + 2, totalNodes);
}

int isMinHeap(struct Node* root) {
    if (!root->left && !root->right)
        return 1;

    if (!root->right)
        return (root->data <= root->left->data);

    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return isMinHeap(root->left) &&
               isMinHeap(root->right);

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) && isMinHeap(root))
        printf("YES");
    else
        printf("NO");

    return 0;
}