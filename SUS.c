#include <stdio.h>
#include <stdlib.h>

int fastPow(int base, int exp) {
    int result = 1;
    while (exp) {
        if (exp & 1) {
            result *= base;
        }
        exp >>= 1;
        base *= base;
    }
    return result;
}

int *findSingleChildNodes(int *preorder, int *postorder, int preStart, int preEnd, int postStart, int postEnd,
                          int *count) {
    // 當 preStart >= preEnd 或 postStart >= postEnd 時，返回空陣列
    if (preStart >= preEnd || postStart >= postEnd) {
        return NULL;
    }
    // 印出當前子樹的前序和後序
    printf("Current subtree preorder: ");
    for (int i = preStart; i < preEnd; i++) {
        printf("%d ", preorder[i]);
    }
    printf("\n");

    printf("Current subtree postorder: ");
    for (int i = postStart; i < postEnd; i++) {
        printf("%d ", postorder[i]);
    }
    printf("\n");
    int *result = (int *)malloc((preEnd - preStart) * sizeof(int));
    int resultIndex = 0;

    // 當preorder的下一個節點是postorder的倒數第二個節點，表示只有一個子節點
    if (preorder[preStart + 1] == postorder[postEnd - 2]) {
        // 有一個子節點的情況
        result[resultIndex++] = preorder[preStart];
        (*count)++;
    }

    // 分割子樹並遞迴處理
    int leftSubtreeSize = 0;
    for (int i = postStart; i < postEnd; i++) {
        if (postorder[i] == preorder[preStart + 1]) {
            leftSubtreeSize = i - postStart + 1;
            break;
        }
    }

    int leftCount = 0;
    int *leftResult = findSingleChildNodes(preorder, postorder, preStart + 1, preStart + leftSubtreeSize, postStart,
                                           postStart + leftSubtreeSize - 1, &leftCount);

    int rightCount = 0;
    int *rightResult = findSingleChildNodes(preorder, postorder, preStart + leftSubtreeSize + 1, preEnd,
                                            postStart + leftSubtreeSize, postEnd - 1, &rightCount);

    // 合併結果
    for (int i = 0; i < leftCount; i++) {
        result[resultIndex++] = leftResult[i];
    }
    for (int i = 0; i < rightCount; i++) {
        result[resultIndex++] = rightResult[i];
    }

    *count += leftCount + rightCount;

    free(leftResult);
    free(rightResult);

    return result;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int preorder[n];
        int postorder[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &preorder[i]);
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &postorder[i]);
        }

        int count = 0;
        int *singleChildNodes = findSingleChildNodes(preorder, postorder, 0, n, 0, n, &count);

        if (count > 0) {
            int result = fastPow(2, count - 1);
            printf("%d\n", result);
        } else {
            printf("0\n");
        }

        free(singleChildNodes);
    }

    return 0;
}
