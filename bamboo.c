#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int heatstroke;
    struct Node* left;
    struct Node* right;
};
typedef struct Node Node;
void build_tree(Node** now, int* arr, int l, int r) {
    if (l > r) {
        *now = NULL;
        return;
    }
    *now = (Node*)malloc(sizeof(Node));
    int mid = (l + r) / 2;
    (*now)->heatstroke = arr[mid];
    build_tree(&(*now)->left, arr, l, mid - 1);
    build_tree(&(*now)->right, arr, mid + 1, r);
}

int query_heatstroke(Node* now, int x) {
    if (now == NULL)
        return 0;
    if (now->heatstroke == x)
        return 1;
    else if (now->heatstroke > x)
        return query_heatstroke(now->left, x);
    else
        return query_heatstroke(now->right, x);
}

void eat_rat(Node** root, int x) {
    if (*root == NULL)
        return;
    if ((*root)->heatstroke == x) {
        Node* temp = *root;
        if ((*root)->left == NULL)
            *root = (*root)->right;
        else if ((*root)->right == NULL)
            *root = (*root)->left;
        else {
            Node* minRight = (*root)->right;
            while (minRight->left != NULL)
                minRight = minRight->left;
            (*root)->heatstroke = minRight->heatstroke;
            eat_rat(&(*root)->right, minRight->heatstroke);
            return;
        }
        free(temp);
    } else if ((*root)->heatstroke > x)
        eat_rat(&(*root)->left, x);
    else
        eat_rat(&(*root)->right, x);
}

void buy_rat(Node** root, int x) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->heatstroke = x;
        (*root)->left = (*root)->right = NULL;
    } else if ((*root)->heatstroke == x)
        return;
    else if ((*root)->heatstroke > x)
        buy_rat(&(*root)->left, x);
    else
        buy_rat(&(*root)->right, x);
}
int main() {
    int n, q, x;
    char operation[20];
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    Node* root = NULL;
    build_tree(&root, arr, 0, n - 1);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%s %d", operation, &x);
        if (strcmp(operation, "heatstroke") == 0) {
            if (query_heatstroke(root, x)) {
                printf("We might as well eat it.\n");
                eat_rat(&root, x);
            } else
                printf("No dinner tonight.\n");
        } else if (strcmp(operation, "buy") == 0)
            buy_rat(&root, x);
    }
    free(arr);
    return 0;
}