#include <stdio.h>
#include <stdlib.h>

// 比較函數，用於 qsort 排序
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);  // 倒序排序
}

// 計算可以購買的最大價值

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, p, k;
        scanf("%d %d %d", &n, &p, &k);
        int a[n + 1];
        a[0] = 0;

        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        qsort(a + 1, n, sizeof(int), compare);

        int cost[n + 1];
        cost[0] = a[0];
        // 計算每組的最高價格總和，並構建前綴和表格
        for (int i = 1; i <= n; i++) {
            if (i < k)
                cost[i] = cost[i - 1] + a[i];
            else
                cost[i] = cost[i - k] + a[i];
        }
        int max_count = 0;
        for (int i = n; i > 0; i--) {
            if (cost[i] <= p) {
                max_count = i;
                break;
            }
        }
        printf("%d\n", max_count);
    }

    return 0;
}