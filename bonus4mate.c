#include <math.h>
#include <stdio.h>
#define MAXVAL 5e9

long long BinarySearch(long long y) {
    for (int i = 0; i < 64; i++) {
        long long two_pow = pow(2, i);
        if (y < two_pow) {
            if (y == two_pow - 1)
                return two_pow;
            else
                return -1;
        }
        long long l = 0, r = MAXVAL, ans = -1;
        int found = 0;
        while (l < r) {
            long long mid = (l + r) / 2;
            long long k = mid * 2 + 1;
            long long check = (two_pow - 1) + mid;
            if (((long double)y / k) > check) {
                l = mid + 1;
            } else if (((long double)y / k) < check) {
                r = mid;
            } else {
                r = mid;
                ans = k;
                found = 1;
            }
        }
        if (found)
            return two_pow * ans;
    }
    return -1;
}
int main() {
    int testcase;
    scanf("%d", &testcase);
    while (testcase--) {
        long long n;
        scanf("%lld", &n);

        if (n == 1)
            printf("2\n");
        else
            printf("%lld\n", BinarySearch(n));
    }
}