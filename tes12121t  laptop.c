#include <math.h>
#include <stdio.h>
#define ll long long
ll cntdigit(ll n, int digit) {
    ll res = 0;
    for (ll j = 1; n / j; j *= 10) {
        ll curdigit = (n / j) % 10;
        res += (n / j / 10) * j;
        if (curdigit > digit)
            res += j;
        else if (curdigit == digit)
            res += n % j + 1;
        if (digit == 0)
            res -= j;
    }
    return res;
}

int main() {
    ll n, a, b;
    int digit = 1; // 要统计的数字

    ll result = 0;
    scanf("%lld", &n);
    for (ll i = 0; i < n; ++i) {
        scanf("%lld%lld", &a, &b);
        a = cntdigit(a, 1);
        b = cntdigit(b, 1);
        result = b - a + 1;
        printf("%lld\n", result);
    }

    return 0;
}
