#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 1000

int tree[MAX_NODES][2];
int nodeData[MAX_NODES];
int nodeCount = 0;

int newNode(int data) {
    int index = nodeCount++;
    nodeData[index] = data;
    tree[index][0] = tree[index][1] = -1;
    return index;
}

int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

int buildTree(int in[], int pre[], int inStrt, int inEnd, int* preIndex) {
    if (inStrt > inEnd)
        return -1;
    int nodeIndex = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (inStrt == inEnd)
        return nodeIndex;
    int inIndex = search(in, inStrt, inEnd, nodeData[nodeIndex]);
    if (inIndex == -1) {
        nodeCount--;
        return -1;
    }
    tree[nodeIndex][0] = buildTree(in, pre, inStrt, inIndex - 1, preIndex);
    tree[nodeIndex][1] = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return nodeIndex;
}

void getPostOrder(int nodeIndex, int postOrder[], int* idx) {
    if (nodeIndex == -1)
        return;
    getPostOrder(tree[nodeIndex][0], postOrder, idx);
    getPostOrder(tree[nodeIndex][1], postOrder, idx);
    postOrder[(*idx)++] = nodeData[nodeIndex];
}

int main() {
    int n, s;
    int p;
    scanf("%d", &p);
    scanf("%d", &n);
    int pre[100000], post[100000];  // 前序 後序
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    scanf("%d", &s);
    for (int i = 0; i < s; i++) {
        int in[n];
        for (int j = 0; j < n; j++)
            scanf("%d", &in[j]);
        int preIndex = 0;
        nodeCount = 0;
        int rootIndex = buildTree(in, pre, 0, n - 1, &preIndex);
        if (rootIndex == -1) {
            printf("no\n");
            continue;
        }
        int postOrder[n];
        int idx = 0;
        getPostOrder(rootIndex, postOrder, &idx);
        int isSame = 1;
        for (int j = 0; j < n; j++) {
            if (postOrder[j] != post[j]) {
                isSame = 0;
                break;
            }
        }
        printf(isSame ? "yes\n" : "no\n");
    }
    return 0;
}
