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

struct TreeNode* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1) return NULL;

    struct TreeNode* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

int countLeaves(struct TreeNode* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n, 0);

    printf("%d\n", countLeaves(root));

    return 0;
}