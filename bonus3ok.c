#include <stdio.h>
#include <stdlib.h>

int cup[200001];

// 檢查在給定天數內是否能完成所需行數
int can_complete_in_days(int* cup, int n, int m, int days) {
    long long total_lines = 0;
    for (int i = 0; i < n; i++) {
        long long reduced_effect = cup[i] - (i / days);
        if (reduced_effect > 0) {
            total_lines += reduced_effect;
        }
        if (total_lines >= m) {
            return 1;
        }
    }
    return total_lines >= m;
}

// 找到完成所需行數的最少天數
int minimum_days_to_complete(int n, int m, int* cup) {
    int left = 1, right = n, result = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (can_complete_in_days(cup, n, m, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &cup[i]);
        }

        int ans = minimum_days_to_complete(n, m, cup);
        printf("%d\n", ans);
    }

    return 0;
}
