#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE {
    int number;
    struct _NODE *ptr_to_right_node;
    struct _NODE *ptr_to_left_node;
} Node;

#define ri ptr_to_right_node
#define le ptr_to_left_node

int search(int *arr, int start, int end, int value) {
    for (int i = start; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}
int preIndex = 0;
Node *buildTree(int *Inorder, int *Preorder, int insrt, int inend) {
    if (insrt > inend)
        return NULL;
    Node *root = (Node *)malloc(sizeof(Node));
    root->number = Preorder[preIndex++];
    root->le = NULL, root->ri = NULL;
    if (insrt == inend)
        return root;
    int inIndex = search(Inorder, insrt, inend, root->number);
    if (inIndex == -1)
        return NULL;
    root->le = buildTree(Inorder, Preorder, insrt, inIndex - 1);
    root->ri = buildTree(Inorder, Preorder, inIndex + 1, inend);
    return root;
}

void showPostorder(Node *node) {
    if (node == NULL)
        return;
    showPostorder(node->le);
    showPostorder(node->ri);
    printf("%d ", node->number);
}

void freeTree(Node *node) {
    preIndex = 0;
    if (node == NULL)
        return;
    freeTree(node->le);
    freeTree(node->ri);
    free(node);
}

int main() {
    int n = 3, id = 1;
    // while (scanf("%d", &n) != EOF) {
    int inorder[3] = {1, 3, 2};
    int preorder[3] = {3, 1, 2};
    int m = 5;
    int inorder1[5] = {7, 6, 9, 8, 10};
    int preorder1[5] = {6, 7, 8, 9, 10};
    // for (int i = 0; i < n; i++)
    //    scanf("%d", &inorder[i]);
    // for (int i = 0; i < n; i++)
    // scanf("%d", &preorder[i]);
    int preIndex = 0;

    Node *root = buildTree(inorder, preorder, 0, n - 1);
    printf("testcase%d: ", id++);
    showPostorder(root);
    printf("\n");
    freeTree(root);

    preIndex = 0;
    Node *root2 = buildTree(inorder1, preorder1, 0, m - 1);
    printf("testcase%d: ", id++);
    showPostorder(root2);
    printf("\n");
    freeTree(root2);
    //}
    return 0;
}