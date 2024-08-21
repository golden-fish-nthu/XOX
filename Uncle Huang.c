#include <stdio.h>
#define ll long long
ll modular_pow(ll base, ll exponent, ll modulus) {
    if (modulus == 1)
        return 0; // assert((modulus - 1) * (modulus - 1) > base);  // Ensure no overflow
    ll result = 1;
    base = base % modulus; // Ensure base is within modulus
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
int main() {

    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    ll ans = modular_pow(a, b, c);
    printf("%lld\n", ans);
}