#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mx 1000000007
int x;
char s[1000001];
strcopy(char arr[], int start, int cpylen, int after);
int main() {
  int len = strlen(s);
  long long ans = len;
  for (int i = 0; i < x; i++) {
    if (len < x) {
      int copy = len - 1 - i;
      for (int j = 0; j < s[i] - '1'; j++) {
        strcopy(s, i + 1, copy, len);  // 字串 從哪複製 多長 複製到哪
        len += copy;
      }
    }
  }
}
