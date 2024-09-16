#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    float a = 9.78, b = 61.80;
    // scanf("%f %f", &a, &b); // 输入两个浮点数
    long long ap = a * 100;
    long long bp = b * 100;
    long long ans = ap * bp;
    char res[10];
    memset(res, 'd', sizeof(res));
    sprintf(res, "%lld", ans);
    char *pch;
    pch = strchr(res, '\0');
    int loc = pch - res - 1;
    if (pch != NULL) {
        for (int i = loc; i >= loc - 4; i--) {
            res[i + 1] = res[i];
        }
    }
    res[loc - 3] = ('.');

    double test = atof(res);
    printf("%.4lf", test);
    putchar('\n');
    return 0;
}