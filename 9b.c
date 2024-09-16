#include <math.h>
#include <stdio.h>
#define MAXN 100000
int x[MAXN], y[MAXN], visited[MAXN];
int n, r;
int distance_squared(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int dfs(int now) {
    visited[now] = 1;
    int result = 1;  // 自己這個點計入result
    for (int i = 0; i < n; i++)
        if (!visited[i] && (distance_squared(now, i) <= r * r))
            result += dfs(i);  // 遞迴呼叫並加上子結果

    return result;
}

int main() {
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        visited[i] = 0;  // 初始化為未拜訪
    }

    int black_holes = 0;
    int remaining_cat_toasts = n;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int group_size = dfs(i);
            if (group_size != 1) {
                black_holes++;
                remaining_cat_toasts -= group_size;
            }
        }
    }

    printf("%d %d\n", remaining_cat_toasts, black_holes);
    return 0;
}
