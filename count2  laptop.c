#include <stdio.h>
#define ll long long
ll fun(ll n) {
  ll ret = 0;
  ll i;
  for (i = 1; i <= n; i *= (ll)10) {
    ll a = n / i;
    ll b = n % i;
    ll x = a % 10;
    if (x == 1) {
      ret += (a / 10) * i + (b + 1);
    } else if (x == 0) {
      ret += (a / 10) * i;
    } else {
      ret += (a / 10 + 1) * i;
    }
  }
  return ret;
}

int main() {
  ll a, b;
  ll ti;
  scanf("%lld", &ti);
  for (int i = 0; i < ti; i++) {
    scanf("%lld%lld", &a, &b);
    ll ra = fun(a), rb = fun(b);
    // if (a == 1)
    printf("%lld\n", rb - ra + 1);
    // else
    //   printf("%lld\n", rb - ra);
  }

  return 0;
}