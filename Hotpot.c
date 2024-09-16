#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int z = 2;
    float a = -48.39, b = 19.234;
    // scanf("%f %f", &a, &b);  // 输入两个浮点数
    long long ap = a * 1000;
    long long bp = b * 1000;
    long long ans = ap * bp;
    char res[20];
    memset(res, 'd', sizeof(res));
    sprintf(res, "%lld", ans);
    char* pch;
    pch = strchr(res, '\0');
    int loc = pch - res - 1;
    if (pch != NULL) {
        for (int i = loc; i >= loc - 6; i--) {
            res[i + 1] = res[i];
        }
    }
    res[loc - 5] = ('.');

    double test = atof(res);
    printf("%.*lf", z, test);
    putchar('\n');
    return 0;
}
