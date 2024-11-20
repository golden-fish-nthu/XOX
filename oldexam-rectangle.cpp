#include <limits.h>
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = INT_MAX;
    int p;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &p);
            if (p < ans) {
                ans = p;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}