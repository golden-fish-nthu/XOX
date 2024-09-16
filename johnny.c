#include <stdio.h>

int count_ways(int arr[], int n, int k, int curr_sum, int idx) {
  // 如果当前和等于 k，则返回 1
  if (curr_sum == k) return 1;

  // 如果当前和大于 k 或者已经遍历完所有数字，则返回 0
  if (curr_sum > k || idx == n) return 0;

  // 选择当前数字和不选择当前数字的两种情况
  int ways_with_curr = count_ways(arr, n, k, curr_sum + arr[idx], idx + 1);
  int ways_without_curr = count_ways(arr, n, k, curr_sum, idx + 1);

  // 返回两种情况的总和
  return ways_with_curr + ways_without_curr;
}

int main() {
  int n, k;
  // 读取输入
  scanf("%d %d", &n, &k);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // 调用递归函数并打印结果
  int result = count_ways(arr, n, k, 0, 0);
  printf("%d\n", result);

  return 0;
}
