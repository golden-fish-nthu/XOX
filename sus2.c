#include <stdio.h>
#include <stdlib.h>

int preIndex = 0;
int err = 0;
int tmp2 = 0;

// 搜索中序陣列中的指定值
int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// 建構樹，儲存於 tree 矩陣
int buildTree(int in[], int pre[], int inStrt, int inEnd, int tree[][2], int n) {
    if (inStrt > inEnd)
        return -1;

    // 確認 preIndex 不超過 n
    if (preIndex >= n) {
        err = 1;  // 錯誤情況
        return -1;
    }

    int current = pre[preIndex++];

    if (inStrt == inEnd)
        return current;

    int inIndex = search(in, inStrt, inEnd, current);
    if (inIndex == -1) {
        err = 1;  // 搜尋失敗，表示數據不正確
        return -1;
    }

    // 遞迴建構左子樹和右子樹
    tree[current][0] = buildTree(in, pre, inStrt, inIndex - 1, tree, n);
    tree[current][1] = buildTree(in, pre, inIndex + 1, inEnd, tree, n);

    return current;
}

// 遞迴獲取後序遍歷
void getPostOrder(int tree[][2], int postOrder[], int ptr) {
    if (ptr == -1)
        return;

    getPostOrder(tree, postOrder, tree[ptr][0]);
    getPostOrder(tree, postOrder, tree[ptr][1]);
    postOrder[tmp2++] = ptr;
}

int main() {
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int n, s;
        scanf("%d", &n);

        int pre[100000], post[100000];
        for (int i = 0; i < n; i++)
            scanf("%d", &pre[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &post[i]);

        scanf("%d", &s);

        for (int i = 0; i < s; i++) {
            int in[n];
            int(*tree)[2] = calloc(n, sizeof(int[2]));  // 使用n確保樹的大小適合

            for (int j = 0; j < n; j++)
                scanf("%d", &in[j]);

            preIndex = 0;
            err = 0;
            tmp2 = 0;

            // 修正：傳入 n 防止索引越界
            int root = buildTree(in, pre, 0, n - 1, tree, n);
            if (err) {
                printf("no\n");
                free(tree);
                continue;
            }

            int postOrder[n];
            getPostOrder(tree, postOrder, root);

            int isSame = 1;
            for (int j = 0; j < n; j++) {
                if (postOrder[j] != post[j]) {
                    isSame = 0;
                    break;
                }
            }

            printf(isSame ? "yes\n" : "no\n");
            free(tree);
        }
    }

    return 0;
}
