#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long fastpow(int x, int n) {
    if (n == 0)
        return 1;
    long long ans = fastpow(x, n / 2);
    if (n % 2 == 0)
        return ans * ans;
    return ans * ans * x;
}

int main() {
    int r = 3;
    char k[30] = {'a', 'b'};
    //  scanf("%s", k);   // 讀取字元集合
    // scanf("%d", &r);  // 讀取想要組成的字串長度

    int s = strlen(k);              // 字元集合的長度
    long long pow = fastpow(s, r);  // 總組合數

    char result[10];  // 用來存放當前組合
    for (int i = 0; i < pow; i++) {
        int num = i;
        for (int j = r - 1; j >= 0; j--) {
            result[j] = k[num % s];  // 根據當前的「位數」選取字元
            num /= s;                // 處理下一位
        }
        result[r] = '\0';        // 字串結尾加上 null 結束符
        printf("%s\n", result);  // 印出當前組合
    }

    return 0;
}
