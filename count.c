#include <math.h>
#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    // (2) 若a大於等於60且小於100則輸出1，否則輸出0。
    if (a >= 60 && a < 100) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    // (3) 計算b+1再除以10的值，四捨五入至小數點後第二位。
    double result = (b + 1) / 10.0;
    printf("%.2f\n", round(result * 100) / 100);

    // (4) 若a大於等於c，則輸出a，否則輸出c。
    if (a >= c) {
        printf("%d\n", a);
    } else {
        printf("%d\n", c);
    }

    return 0;
}
