#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return createNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int search(struct TreeNode* root, int val) {
    if (root == NULL) return 0;

    if (root->val == val) return 1;

    if (val < root->val)
        return search(root->left, val);
    else
        return search(root->right, val);
}

int main() {
    int n;
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int val;
    scanf("%d", &val);

    if (search(root, val))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}