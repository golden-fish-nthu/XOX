#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    double a = 9.78, b = 61.80;
    // scanf("%lf %lf", &a, &b); // 输入两个浮点数
    long long ap = a * 100;
    long long bp = b * 100;
    long long ans = ap * bp;
    char res[10] = {'d'};
    sprintf(res, "%lld", ans);
    char *pch;
    pch = strchr(res, 'd');
    int loc = pch - res - 1;
    if (pch != NULL) {
        for (int i = loc; i >= loc-4; i--) {
            res[i+1] = res[i];
        }
    }
    res[loc-5] = int('.');

    double test = atof(res);
    printf("%.4lf", test);
    putchar('\n');
    return 0;
}