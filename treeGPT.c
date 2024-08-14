#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE {
    int number;
    struct _NODE* ptr_to_right_node;
    struct _NODE* ptr_to_left_node;
} Node;

Node* buildTree(int* inorder, int* preorder, int inorderStart, int inorderEnd) {
    int preorderIndex = 0;
    if (inorderStart > inorderEnd)
        return NULL;
    int current = preorder[preorderIndex];
    preorderIndex++;
    Node* node = (Node*)malloc(sizeof(Node));
    node->number = current;
    node->ptr_to_left_node = NULL;
    node->ptr_to_right_node = NULL;
    if (inorderStart == inorderEnd)
        return node;
    int inorderIndex;
    for (inorderIndex = inorderStart; inorderIndex <= inorderEnd; inorderIndex++)
        if (inorder[inorderIndex] == current)
            break;

    node->ptr_to_left_node = buildTree(inorder, preorder, inorderStart, inorderIndex - 1);
    node->ptr_to_right_node = buildTree(inorder, preorder, inorderIndex + 1, inorderEnd);
    return node;
}

void showPostorder(Node* node) {
    if (node == NULL)
        return;
    showPostorder(node->ptr_to_left_node);
    showPostorder(node->ptr_to_right_node);
    printf("%d ", node->number);
}

void freeTree(Node* node) {
    if (node == NULL)
        return;
    freeTree(node->ptr_to_left_node);
    freeTree(node->ptr_to_right_node);
    free(node);
}

int main() {
    int n;
    int id = 1;
    while (scanf("%d", &n) != EOF) {
        int inorder[100], preorder[100];
        for (int i = 0; i < n; i++)
            scanf("%d", &inorder[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &preorder[i]);
        Node* root = buildTree(inorder, preorder, 0, n - 1);
        printf("testcase%d: ", id++);
        showPostorder(root);
        printf("\n");
        freeTree(root);
    }
    return 0;
}
