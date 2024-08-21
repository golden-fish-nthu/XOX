#include <stdio.h>
#define ll long long
#define MOD 1000000007 // 定义MOD为10^9 + 7

// 矩阵乘法，结果返回到 res
void multiply(ll F[2][2], ll M[2][2]) {
    ll x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % MOD;
    ll y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % MOD;
    ll z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % MOD;
    ll w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % MOD;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

// 矩阵快速幂
void power(ll F[2][2], ll n) {
    if (n == 0 || n == 1)
        return;
    ll M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}

// 计算斐波那契数的函数
ll fibonacci_number(ll n) {
    if (n == 0)
        return 0;
    ll F[2][2] = {{1, 1}, {1, 0}};
    power(F, n - 1);
    return F[0][0];
}

int main() {
    ll n, result;
    while (scanf("%lld", &n) != EOF) { // 读取输入直到EOF
        result = fibonacci_number(n);
        printf("%lld\n", result);
    }
    return 0;
}
