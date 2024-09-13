
#include <stdio.h>
#include <string.h>

// 定义函数来判断两个字符串是否等价
int test(char a[], char b[], int len) {
  // 如果字符串长度为奇数，直接比较字符串是否相等
  if (len % 2 != 0) {
    return strcmp(a, b) == 0;
  } else {
    // 分割字符串为两部分
    int half_len = len / 2;
    char a1[half_len + 1], a2[half_len + 1], b1[half_len + 1], b2[half_len + 1];
    strncpy(a1, a, half_len);
    a1[half_len] = '\0';
    strncpy(a2, a + half_len, half_len);
    a2[half_len] = '\0';
    strncpy(b1, b, half_len);
    b1[half_len] = '\0';
    strncpy(b2, b + half_len, half_len);
    b2[half_len] = '\0';

    // 检查两种情况是否至少有一种是真的
    return (test(a1, b1, half_len) && test(a2, b2, half_len)) ||
           (test(a1, b2, half_len) && test(a2, b1, half_len));
  }
}

int main() {
  int r;
  scanf("%d", &r);
  for (int i = 0; i < r; i++) {
    char str1[1001];
    char str2[1001];
    scanf("%s", str1);
    scanf("%s", str2);
    int len = strlen(str1);
    if (test(str1, str2, len)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}
