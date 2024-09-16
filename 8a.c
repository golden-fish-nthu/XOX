#include <stdio.h>
#include <stdlib.h>

// 比較函數用於 qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// 使用二分搜索查找元素的第一次出現位置
int lower_bound(int* arr, int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// 使用二分搜索查找元素的最後一次出現位置
int upper_bound(int* arr, int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 對數列進行排序
    qsort(arr, n, sizeof(int), compare);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);

        // 使用二分搜索查找 x 在數列中的起始和結束位置
        int lb = lower_bound(arr, n, x);
        int ub = upper_bound(arr, n, x);

        // 計算 x 出現的次數
        int count = ub - lb;
        printf("%d\n", count);
    }

    free(arr);
    return 0;
}