#include <stdio.h>
#include <stdlib.h>
typedef struct _NODE {
    int number;
    struct _NODE* ptr_to_right_node;
    struct _NODE* ptr_to_left_node;
} Node;
Node Head;
void preorder(Node* begin) {
    if (begin) {
        printf("%c ", begin->number);
        preorder(begin->ptr_to_left_node);
        preorder(begin->ptr_to_right_node);
    }
}
void inorder(Node* begin) {
    if (begin) {
        inorder(begin->ptr_to_left_node);
        printf("%c ", begin->number);
        inorder(begin->ptr_to_right_node);
    }
}
void postorder(Node* begin) {
    if (begin) {
        postorder(begin->ptr_to_left_node);
        postorder(begin->ptr_to_right_node);
        printf("%c ", begin->number);
    }
}

int n;
int main() {
    int pre[];
    int mid[];

    return 0;
}

void build(int* pre; int* in) {
    for (int i = 0; i < lenth; i++) {
        Head.number = pre[0];
    }
}
