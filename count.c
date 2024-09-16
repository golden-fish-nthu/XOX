#include <stdio.h>
#define ll long long
int fun2(int i) {
  int ret = 0;
  while (i) {
    ret += ((i % 10) == 1);
    i /= 10;
  }
  return ret;
}
int pre[1000001];
int main() {
  int a, b;
  int ti;
  scanf("%d", &ti);
  for (int i = 0; i < 1000001; i++) {
    int ones = fun2(i);
    pre[i] = ones + pre[i - 1];
  }
  for (int i = 0; i < ti; i++) {
    scanf("%d %d", &a, &b);
    printf("%d\n", pre[b] - pre[a - 1]);
  }

  return 0;
}
