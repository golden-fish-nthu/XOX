#include <stdio.h>
#define MOD 1000000007

struct mtx {
  int ar[3][3];
};
typedef struct mtx mtx;
struct me {
  long long ar[3];
};
typedef struct me me;
mtx times(mtx A, mtx B) {
  mtx temp = {{{0}}};
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        temp.ar[i][j] += ((long long)A.ar[i][k] * B.ar[k][j]) % MOD;
        temp.ar[i][j] %= MOD;
      }
    }
  }

  return temp;
}

mtx fast_pow(mtx A, long long n) {
  mtx B = {{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}};
  while (n) {
    if (n & 1) {
      B = times(B, A);
    }
    A = times(A, A);

    n >>= 1;
  }
  return B;
}

me times2(me A, mtx c);

int main() {
  mtx test = {{{0, 1, 0}, {0, 0, 1}, {1, 2, 1}}};
  me p;
  p.ar[0] = 1;
  p.ar[1] = 12;
  p.ar[2] = 13;
  me ans;
  int t = 1;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    long long x = 10;
    scanf("%lld", &x);
    if (x == 1) {
      printf("%d\n", p.ar[0]);
    } else if (x == 2) {
      printf("%d\n", p.ar[1]);
    } else if (x == 3) {
      printf("%d\n", p.ar[2]);
    } else {
      mtx result = fast_pow(test, x - 3);

      ans = times2(p, result);
      printf("%d\n", ans.ar[2]);
    }
  }
  return 0;
}
me times2(me A, mtx c) {
  me re;
  re.ar[0] = 0;
  re.ar[1] = 0;
  re.ar[2] = 0;

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      re.ar[i] += (+A.ar[j] * c.ar[i][j]) % MOD;
      re.ar[i] %= MOD;
    }
  }

  return re;
}