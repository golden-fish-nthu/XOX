#include <stdio.h>

int jogo(int n, int k) {
    int s = 0;  // 將 s 初始化為 0 對應於只有 1 個人的情況
    for (int i = 2; i <= n; i++)
        s = (s + k) % i;  // 迭代地計算位置

    return s;  // 返回最終位置
}

int main() {
    int n, k, f;
    while (scanf("%d %d", &n, &k) == 2) {
        f = jogo(n, k) + 1;  // 將從 0 開始的索引轉換為從 1 開始
        printf("%d\n", f);
    }
    return 0;
}
