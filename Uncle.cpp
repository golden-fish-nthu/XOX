#include <iostream>
using namespace std;
int jogo(int n, int k);
int main() {
  int n = 5, k = 7, f;
  f = jogo(n, k) + 1;
  cout << f << "\n";
  return 0;
}
int jogo(int n, int k) {
  int s = 0;
  if (n != 1)
    s = (jogo(n - 1, k) + k) % n;
  else
    s = 0;
  return s;  // 返回計算結果
}
