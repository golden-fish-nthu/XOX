#include <iostream>
#include <vector>
using namespace std;

long long test(int now, int x, vector<int>& A, long long index);

int main() {
  long long n;
  vector<int> A = {1, 3, 3, 3, 2, 1, 3, 3, 3};
  n = test(0, 24, A, 0);
  n %= (1000000000 + 7);
  cout << "n = " << n << endl;
}

long long test(int now, int x, vector<int>& A, long long index) {
  int times = A[index];

  vector<int> tmp(A.begin() + index + 1, A.end());
  for (int i = 0; i < times - 1; i++) {
    A.insert(A.end(), tmp.begin(), tmp.end());
  }

  long long length = A.size();
  now++;
  index++;
  if (now < x)
    return test(now, x, A, index);
  else
    return length;
}
