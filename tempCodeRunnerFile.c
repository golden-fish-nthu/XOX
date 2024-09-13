#include <stdio.h>
#define MAXN 100000000
#define ll long long

ll min(ll a, ll b) {
    return ((a > b) ? b : a);
}
ll countTriangles(ll A, ll B, ll C, ll D) {  // 用差分
    ll f[MAXN] = {0};
    ll count = 0;
    for (ll x = A; x <= B; x++)
        f[x + B] += 1, f[x + C + 1] += -1;

    for (ll i = A + B; i <= B + C + 1; i++)
        f[i] += f[i - 1];

    for (ll i = A + B; i <= B + C; i++) {
        if (i <= C)
            continue;
        ll lo = C;
        ll hi = min(i - 1, D);
        count += f[i] * (hi - lo + 1);
    }
    return count;
}
int main() {
    ll T = 1;
    scanf("%d", &T);
    while (T--) {
        ll A = 1, B = 2, C = 3, D = 4;
        scanf("%d %d %d %d", &A, &B, &C, &D);
        ll result = countTriangles(A, B, C, D);
        printf("%d\n", result);
    }
    return 0;
}