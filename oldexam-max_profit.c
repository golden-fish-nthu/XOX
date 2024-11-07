#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* price, int n) {
    int max_profit = 0;
    for (int i = 1; i < n; i++) {
        if (price[i] > price[i - 1]) {
            max_profit += price[i] - price[i - 1];
        }
    }
    return max_profit;
}

int main() {
    int r;
    scanf("%d", &r);
    while (r--) {
        int n;
        scanf("%d", &n);
        int stock[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &stock[i]);
        printf("%d\n", maxProfit(stock, n));
    }
}