#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int a[200005];
int n, k;
int found = 0;
long long m;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int How_many_gcd(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int current_gcd = a[i];
        for (int j = i; j < n; j++) {
            current_gcd = gcd(current_gcd, a[j]);
            if (current_gcd == k) {
                count++;
            }
        }
    }
    return count;
}
int main() {
    cout << How_many_gcd(10);
    return 0;
}
