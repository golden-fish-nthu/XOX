#include <stdio.h>

int count = 0;

void DFS(int n, int row, int cols, int pie, int na);

int main() {
  int n;
  scanf("%d", &n);
  DFS(n, 0, 0, 0, 0);
  printf("%d\n", count);

  return 0;
}

void DFS(int n, int row, int cols, int pie, int na) {
  if (row >= n) {
    count++;
    return;
  }
  int bits = (~(cols | pie | na)) & ((1 << n) - 1);
  while (bits > 0) {
    int p = bits & -bits;
    DFS(n, row + 1, cols | p, (pie | p) << 1, (na | p) >> 1);
    bits &= (bits - 1);
  }
}