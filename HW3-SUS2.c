#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int tree[1000][2];  // 用來存放樹結構，tree[i][0] 為左子節點，tree[i][1] 為右子節點

int search(int* arr, int strt, int end, int val) {
    for (int i = strt; i <= end; i++)
        if (arr[i] == val)
            return i;
    return -1;
}
int preidx = 0;
int build(int* pre, int* post, int l, int h, int size, int idx) {
    if (preidx >= size || l > h)
        return -1;  // 用 -1 表示空節點
    int rotidx = preidx;
    (preidx)++;
    if (preidx >= size || l == h)
        return rotidx;  // 如果只有一個節點或已經遍歷完，直接返回這個節點
    int i = search(post, l, h, pre[preidx]);
    if (i <= h) {
        tree[rotidx][0] = build(pre, post, l, i, size, preidx);          // 左子節點
        tree[rotidx][1] = build(pre, post, i + 1, h - 1, size, preidx);  // 右子節點
    }
    return rotidx;
}
int res = 0;
void child(int idx) {
    if (idx == -1)
        return;
    int leftChild = tree[idx][0];
    int rightChild = tree[idx][1];
    if ((leftChild == -1 && rightChild != -1) || (leftChild != -1 && rightChild == -1))
        (res)++;  // 如果只有一個子節點，計數器增加
    child(leftChild);
    child(rightChild);
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        preidx = 0;
        res = 0;
        int pre[n], post[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &pre[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &post[i]);
        for (int i = 0; i < n; i++)
            tree[i][0] = tree[i][1] = -1;

        build(pre, post, 0, n - 1, n, 0);

        child(0);  // 從根節點開始查找只有一個子節點的節點
        int ans = pow(2, res);
        printf("%d\n", ans);
    }
    return 0;
}