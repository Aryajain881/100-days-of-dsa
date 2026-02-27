#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}


struct Node* insertEnd(struct Node* head, int val) {
    struct Node* temp = createNode(val);
    if (head == NULL)
        return temp;

    struct Node* curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    return head;
}


void findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* p1 = head1;
    struct Node* p2;

    while (p1 != NULL) {
        p2 = head2;
        while (p2 != NULL) {
            if (p1->data == p2->data) {
                printf("%d", p1->data);
                return;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    printf("No Intersection");
}

int main() {
    int n, m, x;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = insertEnd(head1, x);
    }

    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = insertEnd(head2, x);
    }

    findIntersection(head1, head2);
    return 0;
}