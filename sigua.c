#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n + 1];
  int b[n + 1];
  int eaten[n + 2];
  int result[n + 2];
  int ptr = 1;
  for (int i = 0; i < n + 2; i++) eaten[i] = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) {
    if (eaten[b[i]] == 1) {
      result[i] = 0;
    } else {
      // 初始化当前西瓜索引为1
      int eat = 0;
      while (ptr <= n && a[ptr] != b[i]) {
        eaten[a[ptr]] = 1;
        eat++;
        ptr++;
      }
      // 将结果存储到结果数组中
      eat++;
      eaten[ptr] = 1;
      ptr++;
      result[i] = eat;
    }
  }

  // 输出每个要吃的西瓜需要吃掉的西瓜数量
  for (int i = 1; i <= n; i++) {  // 将循环上界改为 n + 1
    printf("%d", result[i]);
    if (i < n + 1) {
      printf(" ");
    }
  }
  printf("\n");

  return 0;
}