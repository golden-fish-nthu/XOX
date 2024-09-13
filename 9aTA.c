#include <limits.h>
#include <stdio.h>
long long ckpt[100003];
long long dis[100003];
int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    ckpt[0] = 0;
    for (int i = 1; i <= n; i++)
        scanf("%lld", &ckpt[i]);
    for (int i = 0; i < n; i++) {
        dis[i] = ckpt[i + 1] - ckpt[i];
    }

    long long current = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (dis[i] > k) {
            printf("The Legend Falls.");
            return 0;
        }
        if (current + dis[i] > k) {
            ans++;
            current = 0;
        }
        current += dis[i];
    }
    printf("%lld", ans);
}