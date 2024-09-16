#include <stdio.h>
int main() {
    long A, B, C, a, b, c;
    scanf("%ld %ld %ld", &A, &B, &C);
    a = (A - B + C) / 2;
    b = A - a;
    c = B - b;
    printf("%ld %ld %ld\n", a, b, c);
    return 0;
}  // 168 134 112