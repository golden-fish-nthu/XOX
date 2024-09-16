#include <stdio.h>

// 计算两个数的最大公约数
int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// 计算n个数中两两组合的最大公约数的最大值
int max_gcd_pair(int arr[], int n) {
  int max_gcd = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int current_gcd = gcd(arr[i], arr[j]);
      if (current_gcd > max_gcd) {
        max_gcd = current_gcd;
      }
    }
  }
  return max_gcd;
}

int main() {
  int t;
  scanf("%d", &t);  // 读取测试用例数量

  while (t--) {
    int n;
    scanf("%d", &n);  // 读取孩子数量

    int arr[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);  // 读取每个孩子想要的糖的数量
    }

    // 计算n个数中两两组合的最大公约数的最大值
    int max_sugar = max_gcd_pair(arr, n);

    printf("%d\n", max_sugar);  // 输出最大糖的数量
  }

  return 0;
}
