#include <stdio.h>
#define ll long long
ll fast_pow(ll x, ll n, ll m);
ll modular_pow(ll base, ll exponent, ll modulus);
int main() {
  // (x^y)%m
  ll x, y, m, n;
  scanf("%lld%lld%lld", &x, &y, &m);
  n = modular_pow(x, y, m);
  printf("%lld\n", n);
}
ll fast_pow(ll x, ll n, ll m) {
  if (n == 1) {
    return x;
  }
  if (n % 2 == 0) {
    ll xk = fast_pow(x, n / 2, m);
    return (xk * xk) % m;
  } else {
    ll xk = fast_pow(x, (n - 1) / 2, m);
    return (x * xk * xk) % m;
  }
}
ll modular_pow(ll base, ll exponent, ll modulus) {
  if (modulus == 1) {
    return 0;
  }
  // assert((modulus - 1) * (modulus - 1) > base);  // Ensure no overflow
  ll result = 1;
  base = base % modulus;  // Ensure base is within modulus
  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = (result * base) % modulus;
    }
    exponent = exponent >> 1;
    base = (base * base) % modulus;
  }
  return result;
}