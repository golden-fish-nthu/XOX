#include <stdio.h>
#include <stdlib.h>

int countTreesUtil(int pre[], int post[], int* preIndex, int l, int h, int size) {
    // Base case
    if (*preIndex >= size || l > h)
        return 1;

    // The first node in preorder traversal is root. So take the node at
    // preIndex from preorder and make it root, and increment preIndex
    int root = pre[*preIndex];
    ++*preIndex;

    // If the current subarray has only one element, no need to recur
    if (l == h)
        return 1;

    // Search the next element of pre[] in post[]
    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;

    // Use the index of element found in postorder to divide
    // postorder array in two parts. Left subtree and right subtree
    int leftCount = 0, rightCount = 0;
    if (i <= h) {
        leftCount = countTreesUtil(pre, post, preIndex, l, i, size);
        rightCount = countTreesUtil(pre, post, preIndex, i + 1, h - 1, size);
    }

    return leftCount * rightCount;
}

int countTrees(int pre[], int post[], int size) {
    int preIndex = 0;
    return countTreesUtil(pre, post, &preIndex, 0, size - 1, size);
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        int pre[n], post[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &pre[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &post[i]);
        }

        int result = countTrees(pre, post, n);
        printf("%d\n", result);
    }

    return 0;
}
