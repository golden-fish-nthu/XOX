#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countsubstrings(char s[]);
int countpalindrom(char s[], int leftChar, int rightChar);
int main() {
  int t;
  scanf("%d", &t);
  char r[t][2001];
  for (int i = 0; i < t; i++) {
    scanf("%s", r[i]);
    int ans = countsubstrings(r[i]);
    printf("%d\n", ans);
  }

  return 0;
}
// 计算字符串s中的回文子串数量
int countsubstrings(char s[]) {
  int count = 0;
  for (int i = 0; i < strlen(s); i++) {
    count += countpalindrom(s, i, i);  // 以当前字符为中心的回文子串数量
    count += countpalindrom(s, i - 1, i);
    // 以当前字符和前一个字符为中心的回文子串数量
  }
  return count;
}
// 计算以leftChar和rightChar为中心的回文子串数量
int countpalindrom(char s[], int leftChar, int rightChar) {
  int count = 0;
  while (leftChar >= 0 && rightChar < strlen(s) && s[leftChar] == s[rightChar])
    count++, leftChar--, rightChar++;

  return count;
}