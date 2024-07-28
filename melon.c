#include <stdio.h>

#define MAX_N 200000

int main() {
    int n;
    scanf("%d", &n);

    int a[MAX_N];
    int b[MAX_N];
    int ans[MAX_N];
    int positions[MAX_N];
    char eaten[MAX_N] = {0};

    // 讀取初始位置並填充 positions 陣列
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        positions[a[i] - 1] = i;
    }

    // 讀取吃西瓜的順序
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int lastEaten = -1; // 記錄最後一個被吃掉的西瓜索引
    for (int i = 0; i < n; i++) {
        int current = b[i] - 1; // 當前要吃的西瓜索引（0-based）
        if (eaten[positions[current]]) {
            ans[i] = 0; // 如果已經被吃掉，則需要吃掉 0 個西瓜
        } else {
            ans[i] = positions[current] - lastEaten; // 計算需要吃掉的西瓜數量
            for (int j = lastEaten + 1; j <= positions[current]; j++) {
                eaten[j] = 1; // 更新從 lastEaten+1 到當前西瓜之間所有西瓜的狀態
            }
            lastEaten = positions[current]; // 更新最後一個被吃掉的西瓜索引
        }
    }

    // 輸出結果
    for (int i = 0; i < n; i++) {
        printf("%d", ans[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
