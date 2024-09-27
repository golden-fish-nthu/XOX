#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(char data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(char arr[], int strt, int end, char value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Node *buildTree(char pre[], char post[], int *preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h)
        return NULL;

    Node *root = newNode(pre[*preIndex]);
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

void printPreorder(Node *node) {
    if (node == NULL)
        return;
    printf("%c ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(Node *node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%c ", node->data);
}

void findSingleChildNodes(Node *node) {
    if (node == NULL)
        return;
    if ((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL)) {
        printf("%c ", node->data);
    }
    findSingleChildNodes(node->left);
    findSingleChildNodes(node->right);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    char pre[n], post[n];
    printf("Enter the preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &pre[i]);
    }

    printf("Enter the postorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &post[i]);
    }

    int preIndex = 0;
    Node *root = buildTree(pre, post, &preIndex, 0, n - 1, n);

    printf("Nodes with only one child: \n");
    findSingleChildNodes(root);

    printf("\nPreorder of the constructed tree: \n");
    printPreorder(root);

    printf("\nPostorder of the constructed tree: \n");
    printPostorder(root);

    return 0;
}