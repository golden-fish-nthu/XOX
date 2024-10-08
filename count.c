#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
long long cntdigit(long long n, long long digit) {
    long long j;                           // pointer
    long long res = 0;                     // 暫存器
    for (j = 1; n / j; j *= 10) {          // 位數進位
        long long curdigit = (n / j) % 10; // 目前計算的位數
        res += (n / j / 10) * j;
        if (curdigit > digit) // 判斷是不是特例(舉例來說 346 -->找3 會剩)
            res += j;
        else if (curdigit == digit) // 313找3
            res += n % j + 1;

        if (digit == 0) // 301找3
            res -= j;
    }
    return res;
}
int main() {
    int i;
    scanf("%d", &i);
    while (i--) {
        long long a, b;
        long long tar = 1;
        scanf("%lld %lld", &a, &b);
        long long res = cntdigit(b, tar) - cntdigit(a - 1, tar);
        printf("%lld\n", res);
    }
}