#include <stdio.h>
#include <stdlib.h>

// Define structure for tree node
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
int findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root->val; // LCA found
    }
    return -1; // If not found
}

int main() {
    int n, val, p, q;
    struct Node* root = NULL;

    // Input
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d %d", &p, &q);

    // Output LCA
    printf("%d\n", findLCA(root, p, q));

    return 0;
}