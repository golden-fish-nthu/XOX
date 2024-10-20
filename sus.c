#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
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

Node *buildTree(int in[], int pre[], int inStrt, int inEnd, int *preIndex) {
    if (inStrt > inEnd)
        return NULL;

    Node *tNode = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);
    if (inIndex == -1) {
        free(tNode);
        return NULL;
    }
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, preIndex);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

void printPostOrder(Node *node) {
    if (node == NULL)
        return;

    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%d ", node->data);
}

void getPostOrder(Node *node, int postOrder[], int *idx) {
    if (node == NULL)
        return;
    getPostOrder(node->left, postOrder, idx);
    getPostOrder(node->right, postOrder, idx);
    postOrder[(*idx)++] = node->data;
}

int main() {
    int n, s;
    scanf("%d", &n);

    int pre[100000], post[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }

    scanf("%d", &s);

    for (int i = 0; i < s; i++) {
        int in[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &in[j]);
        }

        int preIndex = 0;
        Node *root = buildTree(in, pre, 0, n - 1, &preIndex);
        if (root == NULL) {
            printf("no\n");
            continue;
        }
        int postOrder[n];
        int idx = 0;
        getPostOrder(root, postOrder, &idx);

        int isSame = 1;
        for (int j = 0; j < n; j++) {
            if (postOrder[j] != post[j]) {
                isSame = 0;
                break;
            }
        }

        if (isSame) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}