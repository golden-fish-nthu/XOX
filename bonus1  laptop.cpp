#include <iostream>
#include <utility>
#include <vector>
using namespace std;
// 原本想法應該跟考試3的stupid TA很像 就是把串列想成1 k 2k 三種東西去排
// 公式就是1作為切割點 子序列sigma(K&2K)-子序列(2K) 可是現在卡在
// 如果有不只一個2K子序列該怎麼辦 ex:(5,11,3)
long long sigma(long long r) { return (r * (r + 1)) / 2; }  // 求和的
pair<int, int> dec(int m) {
  // 偵測的 看看是不是可以直接sigma ex:(3,6,2) or (10,3,2)
  int i = 1;
  while (sigma(i) < m) ++i;
  if (sigma(i) == m)
    return pair(i, 0);  // 可以就塞0
  else {
    int r = sigma(i) - m;
    return pair(i, r);  // 需要放2K就回傳多的數量 嘗試用2K消
  }
}  // 其實還有一個是若n長度小於i的時候return -1 還沒做
void seq(int n, int m, int k) {  // 主程式
  int sequ[n];
  int k1, k2, k3;
  for (int i = 0; i < n; ++i) sequ[i] = 1;  // 全部先塞一
  pair<int, int> tmp = dec(m);
  if (tmp.second != 0) {  // 若需要2K
    int i = 1;
    while (sigma(i) < tmp.second) ++i;
    if (sigma(i) == m)
      k2 = i;  // K2就是2K數量
    else {
      int r = tmp.second - sigma(i - 1);  // 多於一個2K子串列
      int j = 1;
      while (sigma(j) < r) {
        j++;
      }
      k2 = j;             // 第一個2K
      k3 = r - sigma(j);  // 第二個2K
    }
  } else {
    k1 = tmp.first;  // 只有K
  }
}  // 還缺把sequ陣列透過k1k2k3轉換成答案的部分

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  seq(n, m, k);
  return 0;
}
