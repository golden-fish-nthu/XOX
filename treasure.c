#include <stdio.h>
#define MAX_N 1000006
int boxs[MAX_N];
long long pre[MAX_N];
int main() {
    int time, box;
    scanf("%d%d", &time, &box);
    for (int i = 0; i < box; i++)
        scanf("%d", &boxs[i]);
    pre[0] = ((boxs[0] >= 0) ? boxs[0] : 0);
    for (int i = 1; i < box; i++)
        pre[i] = ((boxs[i] >= 0) ? (boxs[i] + pre[i - 1]) : pre[i - 1]);
    for (int i = 0; i < time; i++) {
        int head, end, num;
        scanf("%d%d%d", &head, &end, &num);
        long long total;
        if (head != 1)
            total = pre[head + num - 2] - pre[head - 2];
        else
            total = pre[head + num - 2];
        printf("%lld\n", total);
    }
    return 0;
}