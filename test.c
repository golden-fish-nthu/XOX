#include <stdio.h>
#include <stdlib.h>
int cmpp(const void* a, const void* b) {
    long long* ra = (long long*)a;
    long long* rb = (long long*)b;

    return ((*ra > *rb) ? 1 : -1);
}
int main() {
    long long data[12] = {8, 9, 10, 11, 12, 1, 2, 3, 4, 5, 6, 7};
    qsort(data, 12, sizeof(long long), cmpp);
    for (long long i = 0; i < 12; i++) {
        printf("%lld  ", data[i]);
    }
	printf("\n");
    return 0;
}
