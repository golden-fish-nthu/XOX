#include <algorithm>
#include <cstring>  // For memset
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 50005;  // 最大範圍
int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;

        int f[2 * MAXN] = {0};  // 差分數組
        long long lenth = 2 * MAXN;
        // Step 1: 計算 [x + B, x + C] 的差分數組
        for (int x = A; x <= B; ++x)
            f[x + B]++, f[x + C + 1]--;

        // Step 2: 將差分數組轉換為前綴和數組
        for (int i = 1; i < lenth; ++i)
            f[i] += f[i - 1];

        // Step 3: 計算答案
        long long ans = 0;  // 使用 long long 防止溢位
        for (int i = A + B; i <= B + C; ++i) {
            int num_of_z = max(min(D, i - 1) - C + 1, 0);  // 有效 z 的數量
            ans += f[i] * num_of_z;                        // 記得轉型為 long long
        }

        cout << ans << endl;
    }
}
