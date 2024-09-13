#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double left, right;
} Interval;

// 比較函數，用於排序
int compare(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    if (intervalA->left < intervalB->left)
        return -1;
    if (intervalA->left > intervalB->left)
        return 1;
    if (intervalA->right < intervalB->right)
        return -1;
    if (intervalA->right > intervalB->right)
        return 1;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        long long N;
        int Q;
        scanf("%lld %d", &N, &Q);

        Interval intervals[Q];
        for (int i = 0; i < Q; i++) {
            scanf("%lf %lf", &intervals[i].left, &intervals[i].right);
        }

        // 對所有區間按左端點進行排序
        qsort(intervals, Q, sizeof(Interval), compare);

        // 合併區間
        double coveredLength = 0;
        double currentStart = intervals[0].left;
        double currentEnd = intervals[0].right;

        for (int i = 1; i < Q; i++) {
            if (intervals[i].left <= currentEnd) {
                if (intervals[i].right > currentEnd) {
                    currentEnd = intervals[i].right;
                }
            } else {
                coveredLength += currentEnd - currentStart;
                currentStart = intervals[i].left;
                currentEnd = intervals[i].right;
            }
        }
        coveredLength += currentEnd - currentStart;

        // 計算安全位置的比例
        double safeRatio = (N - coveredLength) / N;
        printf("%.6lf\n", safeRatio);
    }

    return 0;
}
