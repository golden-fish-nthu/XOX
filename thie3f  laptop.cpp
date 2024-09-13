#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
long long test(int now, int x, vector<int> A, long long index);
int main() {
  long long n;
  vector<int> A = {3, 3, 3};
  n = test(0, 6, A, 0);
  n %= (1000000000 + 7);
  cout << "n = " << n << endl;
}
long long test(int now, int x, vector<int> A, long long index) {
  vector<int> b(A.begin(), A.begin() + index);
  // for (int i = 0; i < b.size(); i++) cout << "b:" << b[i] << " ";
  // putchar('\n');
  vector<int> c(A.begin() + index + 1, A.end());
  // for (int i = 0; i < c.size(); i++) cout << "c:" << c[i] << " ";
  // putchar('\n');
  int times = A[index];
  for (int i = 0; i < times - 1; i++) {
    A.insert(A.end(), c.begin(), c.end());
  }
  long long lenth = A.size();
  // for (int i = 0; i < A.size(); i++) cout << "A now:" << A[i] << " ";
  // putchar('\n');
  now++;
  index++;
  cout << "now:" << now << endl;
  if (now < x)
    return test(now, x, A, index);
  else
    return lenth;
}