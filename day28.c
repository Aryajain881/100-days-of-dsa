#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, val;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    if (n <= 0) {
        return 0;
    }

    // Create first node
    scanf("%d", &val);
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = val;
    head->next = head;   // circular link
    temp = head;

    // Create remaining nodes
    for (i = 1; i < n; i++) {
        scanf("%d", &val);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = head;
        temp->next = newNode;
        temp = newNode;
    }

    // Traverse circular linked list
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}