#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
int min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    int totl = 6;
    scanf("%d", &totl);
    int h[7] = {30, 10, 60, 10, 60, 50};
    int dp[totl + 3];
    int dp2[totl + 3];
    // for (int i = 0; i < totl; i++)
    //     scanf("%d", &h[i]);
    dp[0] = 0;
    dp2[0] = 0;
    for (int i = 1; i < totl; i++)
        dp[i] = 10000000, dp2[i] = 10000000;
    for (int i = 0; i < totl; i++) {
        if (i + 1 < totl)
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));

        if (i + 2 < totl)
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    }
    dp[1] = dp[0] + abs(h[1] - h[0]);
    for (int i = 2; i < totl; i++) {
        dp2[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp2[i - 2] + abs(h[i] - h[i - 2]));
    }
    // for (int i = 0; i < totl; i++)
    // printf("%d ", dp[totl - 1]);
}