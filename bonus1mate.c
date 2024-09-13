#include <stdio.h>
int a[200005];
int n, k;
long long m;
int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}
int How_many_gcd(int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    int current_gcd = a[i];
    for (int j = i; j < n; j++) {
      current_gcd = gcd(current_gcd, a[j]);
      if (current_gcd == 2) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  // int t;
  // scanf("%d",&t);

  // scanf("%d %lld %d",&n,&m,&k);
  n = 5;
  m = 13;
  k = 2;
  for (int i = 0; i < n; i++) {
    a[i] = k;
  }
  printf("%d\n", How_many_gcd(n));
  return 0;
}
