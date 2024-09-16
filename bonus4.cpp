#include <algorithm>
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;
ll my_min(ll a, ll b) {
    return a < b ? a : b;
}
ll power_of(int exponent) {
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return 2;
    ll result = 1, base = 2;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}
ll cal(ll stu) {
    ll matches = 0;
    while (stu > 1) {
        if (stu % 2 == 0) {
            matches += stu / 2;
            stu /= 2;
        } else {
            matches += stu * (stu - 1) / 2;
            break;
        }
    }
    return matches;
}
int binarySearch(ll i, ll n) {
    ll lo = 1, hi = n;
    bool found = false; // 标志变量，用于指示是否找到目标数据
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        ll s = power_of(i) * mid;
        ll matches = cal(s);
        if (matches == n) {
            return mid;
        } else if (matches < n) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
        if (lo > hi) { // 检查 lo 是否大于 hi，如果是，则表示搜索范围内一定没有目标数据
            found = false;
            break;
        }
    }
    if (!found) {
        // 在此处添加任何你希望执行的代码，以处理没有找到目标数据的情况
        return -1;
    }
    return -1;
}
int main() {
    int T = 1;
    // cin >> T;
    for (int j = 0; j < T; j++) {
        ll n = 4;
        // cin >> n;
        int mi = -1;
        for (int i = 0; i < 63; ++i) {
            int k = binarySearch(i, n);
            if (k != -1) {
                mi = (mi == -1) ? (power_of(i) * k) : my_min((power_of(i) * k), mi);
            }
        }
        cout << mi << endl;
    }
    return 0;
}
