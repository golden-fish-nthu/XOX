#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *gets(char *str);
struct Node {
    char *value;
    struct Node *left, *right;
};
int isOperator(char *token) {
    return strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0;
}
struct Node *buildTree(char **tokens, int *index) {
    struct Node *node = malloc(sizeof(struct Node));
    node->value = tokens[*index];
    if (isOperator(tokens[*index])) {
        (*index)++;
        node->left = buildTree(tokens, index);
        (*index)++;
        node->right = buildTree(tokens, index);
    } else
        node->left = node->right = NULL;
    return node;
}
int postorderEvaluate(struct Node *node, int x, int y, int z) {
    if (node == NULL)
        return 0;
    if (node->left == NULL && node->right == NULL) {
        if (strcmp(node->value, "x") == 0)
            return x;
        else if (strcmp(node->value, "y") == 0)
            return y;
        else if (strcmp(node->value, "z") == 0)
            return z;
        else
            return atoi(node->value);
    }
    int leftValue = postorderEvaluate(node->left, x, y, z), rightValue = postorderEvaluate(node->right, x, y, z);
    if (strcmp(node->value, "+") == 0)
        return leftValue + rightValue;
    else if (strcmp(node->value, "-") == 0)
        return leftValue - rightValue;
    else if (strcmp(node->value, "*") == 0)
        return leftValue * rightValue;
    else if (strcmp(node->value, "/") == 0)
        return leftValue / rightValue;
    return 0;
}
void inorder(struct Node *node) {
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%s", node->value);
    inorder(node->right);
}
int main() {
    char expression[100];
    char *tokens[20];
    gets(expression);
    char *token = strtok(expression, " ");
    int n = 0;
    while (token != NULL) {
        tokens[n++] = token;
        token = strtok(NULL, " ");
    }
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    int index = 0;
    struct Node *root = buildTree(tokens, &index);
    inorder(root);
    int result = postorderEvaluate(root, x, y, z);
    printf("\n%d\n", result);
    return 0;
}
