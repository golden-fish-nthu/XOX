#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1001
#define MAX_N 1001

// 比较函数，用于 qsort 排序
int compare(const void* a, const void* b) {
    int ra = strlen((char*)a);
    int rb = strlen((char*)b);
    return (ra - rb);
}

int main() {
    int n;
    char strings[MAX_N][MAX_LEN];
    // 读取输入
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    // 根据长度排序字符串
    qsort(strings, n, sizeof(strings[0]), compare);

    for (int i = 0; i < n - 1; i++) {
        if (!strstr(strings[i + 1], strings[i])) {
            printf("NO\n");
            return 0;
        }
    }

    // 如果可以按要求排序，输出结果
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}