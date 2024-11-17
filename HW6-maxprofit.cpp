#include <stdio.h>
#define ll long long

ll maxProfit(int d, int *prices) {
    ll profit = 0; // 紀錄最大利潤
    for (int i = 1; i < d; i++)
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    return profit;
}
int prices[100001];
int main() {
    int t; // 測試案例數量
    scanf("%d", &t);

    while (t--) {
        int d;
        scanf("%d", &d); // 天數

        for (int i = 0; i < d; i++) {
            scanf("%d", &prices[i]); // 每天的股價
        }

        ll result = maxProfit(d, prices);
        printf("%lld\n", result);
    }

    return 0;
}
