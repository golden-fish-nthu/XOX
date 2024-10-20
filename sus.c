#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Node *buildTree(char in[], char pre[], int inStrt, int inEnd, int *preIndex) {
    if (inStrt > inEnd)
        return NULL;

    Node *tNode = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (inStrt == inEnd)
        return tNode;

    int inIndex = search(in, inStrt, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, preIndex);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

void printPostOrder(Node *node) {
    if (node == NULL)
        return;

    printPostOrder(node->left);
    printPostOrder(node->right);
    printf("%c", node->data);
}

int main() {
    int n, s;
    scanf("%d", &n);

    char pre[n + 1], post[n + 1];
    scanf("%s %s", pre, post);

    scanf("%d", &s);

    for (int i = 0; i < s; i++) {
        char in[n + 1];
        scanf("%s", in);

        int preIndex = 0;
        Node *root = buildTree(in, pre, 0, n - 1, &preIndex);

        char result[n + 1];
        result[0] = '\0';
        printPostOrder(root);
        printf("\n");

        char postOrder[n + 1];
        int idx = 0;
        void getPostOrder(Node * node) {
            if (node == NULL)
                return;
            getPostOrder(node->left);
            getPostOrder(node->right);
            postOrder[idx++] = node->data;
        }
        getPostOrder(root);
        postOrder[idx] = '\0';

        if (strcmp(postOrder, post) == 0) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}