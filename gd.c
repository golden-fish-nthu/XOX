#include <stdio.h>
int main() {
    int a[5001];
    int n;
    int k;
    long long prefixSum[5001];
    prefixSum[0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        prefixSum[i + 1] = prefixSum[i] + a[i];
    }
    double maxAverage = -1e9;
    for (int i = 0; i <= n - k; i++) {
        for (int j = i + k - 1; j < n; j++) {
            long long sum = prefixSum[j + 1] - prefixSum[i];
            int length = j - i + 1;
            double average = (double)sum / length;
            if (average > maxAverage)
                maxAverage = average;
        }
    }
    printf("%.3f\n", maxAverage);
    return 0;
}