#include <stdio.h>
#define ll long long
#define max 2000002
int arr[max];
ll prefix[max];
void prefixSum(int n, int a[], ll prefix[]) {
    prefix[1] = a[1];
    for (int i = 2; i <= n; i++)
        prefix[i] = prefix[i - 1] + a[i];
}
ll sum(int a, int b, int n, ll prefix[]) {
    if (a < b)
        return (a != 1) ? prefix[b] - prefix[a - 1] : prefix[b];
    else if (a > b)
        return prefix[n] - prefix[a - 1] + prefix[b];
    else
        return arr[a];
}
int main() {
    int n, q, a, b;
    int max_a = 1, max_b = 1;
    ll max_sum = -1;
    while (scanf("%d %d", &n, &q) != EOF) {
        arr[0] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        prefixSum(n, arr, prefix);
        max_sum = -1, max_a = 1, max_b = 1;
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &a, &b);
            ll current_sum = sum(a, b, n, prefix);
            if (current_sum > max_sum)
                max_sum = current_sum, max_a = a, max_b = b;
        }
        printf("Max_range: (%d,%d); Value: %lld\n", max_a, max_b, max_sum);
    }
    return 0;
}