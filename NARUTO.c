#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int index = 0;
char* gets(char* str);
struct Node {
    char* value;  // 存储變數、數字或運算符，使用指針以存儲多字符
    struct Node *left, *right;
};

int oper(char* token) {
    return (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0);
}

struct Node* buildTree(char** tokens) {
    struct Node* node = malloc(sizeof(struct Node));
    node->value = tokens[index];  // 將當前 token 賦值給節點的 value
    if (oper(tokens[index])) {
        (index)++;
        node->left = buildTree(tokens);
        (index)++;
        node->right = buildTree(tokens);
    } else
        node->left = node->right = NULL;  // 如果是葉節點，沒有左右子樹
    return node;
}

int calculate(struct Node* node, int x, int y, int z) {
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
            return atoi(node->value);  // 將字串轉為整數
    }
    int leftValue = calculate(node->left, x, y, z), rightValue = calculate(node->right, x, y, z);
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
void inorder(struct Node* node) {
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%s", node->value);
    inorder(node->right);
}

int main() {
    char expression[101];
    char* tokens[20];
    gets(expression);
    char* token = strtok(expression, " ");
    int n = 0;
    while (token != NULL) {
        tokens[n++] = token;
        token = strtok(NULL, " ");
    }
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    struct Node* root = buildTree(tokens);
    inorder(root);
    int result = calculate(root, x, y, z);
    printf("\n%d\n", result);
    return 0;
}