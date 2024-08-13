/*
Construct tree by inorder and preorder
Description
This problem is partial judge!
We will give you the "inorder" and "preorder" of a tree.
You need to construct a tree by the "inorder" and "preorder" we give you and
print the "postorder",
There are three function you need to complete.
Node* buildTree(int *inorder, int *preorder, int
function to construct the tree.
void showPostorder(Node *root)
function to print the postorder
void freeTree (Node *root)
function to free the tree


Notice that the the final testcase has small memory limit. If you don't free your tree you will get memory limit
exceeded Input There are multiple testcases. The testcases will end With EOF. Each testcase contains three lines. First
line only contains one integer n(l n <= 100) which means the number of nodes in the tree. Second line contains n
integers which in the range of int . Standing for the "inorder". Third line contains n integers which in the range of
int . Standing for the "preorder". Output For each testcase output the "postorder" of the tree. Each number should be
followed by a single blank(even the last number).

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *left, *right;
};
typedef struct Node Node;
void preorder(Node *begin) {
    if (begin) {
        printf("%c ", begin->data);
        preorder(begin->left);
        preorder(begin->right);
    }
}
void inorder(Node *begin) {
    if (begin) {
        inorder(begin->left);
        printf("%c ", begin->data);
        inorder(begin->right);
    }
}
void postorder(Node *begin) {
    if (begin) {
        postorder(begin->left);
        postorder(begin->right);
        printf("%c ", begin->data);
    }
}

int main() {
    Node *head, *p1, *p2, *p3, *p4, *p5, *p7;
    p1 = (Node *)malloc(sizeof(Node));
    p1->data = 'A';
    head = p1;
    p2 = (Node *)malloc(sizeof(Node));
    p2->data = 'B';
    p3 = (Node *)malloc(sizeof(Node));
    p3->data = 'C';
    p4 = (Node *)malloc(sizeof(Node));
    p4->data = 'D';
    p5 = (Node *)malloc(sizeof(Node));
    p5->data = 'E';
    p7 = (Node *)malloc(sizeof(Node));
    p7->data = 'F';
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->left = NULL;
    p3->right = p7;
    p4->left = NULL;
    p4->right = NULL;
    p5->left = NULL;
    p5->right = NULL;
    p7->left = NULL;
    p7->right = NULL;
    preorder(head);
    printf("\n");
    inorder(head);
    printf("\n");
    postorder(head);
    return 0;
}