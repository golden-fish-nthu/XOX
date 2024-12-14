#include <stdio.h>
#include <stdlib.h>
int res = 0;
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int fastPow(int base, int exp) {
    int result = 1;
    while (exp) {
        if (exp & 1) {
            result *= base;
        }
        exp >>= 1;
        base *= base;
    }
    return result;
}
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int pre[], int post[], int* preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h)
        return NULL;

    Node* root = newNode(pre[*preIndex]);
    ++(*preIndex);

    if (l == h || *preIndex >= size)
        return root;

    int i = search(post, l, h, pre[*preIndex]);

    if (i <= h) {
        root->left = buildTree(pre, post, preIndex, l, i, size);
        root->right = buildTree(pre, post, preIndex, i + 1, h - 1, size);
    }

    return root;
}

void findSingleChildNodes(Node* node) {
    if (node == NULL)
        return;
    if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)) {
        // printf("%d ", node->data);
        res++;
    }
    findSingleChildNodes(node->left);
    findSingleChildNodes(node->right);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        res = 0;
        int pre[n], post[n];
        // printf("Enter the preorder traversal: ");
        for (int i = 0; i < n; i++) {
            scanf(" %d", &pre[i]);
        }

        // printf("Enter the postorder traversal: ");
        for (int i = 0; i < n; i++) {
            scanf(" %d", &post[i]);
        }

        int preIndex = 0;
        Node* root = buildTree(pre, post, &preIndex, 0, n - 1, n);

        // printf("Nodes with only one child: \n");
        findSingleChildNodes(root);
        // printf("%d\n", res);
        int ans = fastPow(2, res);
        printf("%d\n", ans);
    }
    return 0;
}