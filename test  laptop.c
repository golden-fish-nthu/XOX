#include <stdio.h>
int main() {
    unsigned long long test;
    unsigned long long test2;
    scanf("%lld%lld",&test,&test2);
    test *= test2;
    printf("%lld\n", test);
}