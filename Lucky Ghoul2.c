#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, q;
    while (scanf("%d %d", &n, &q) != EOF) {
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < q; i++) {
            int ai;
            scanf("%d", &ai);
            int* item = (int*)bsearch(&ai, arr, n, sizeof(int), compare);
            if (item != NULL) {
                printf("%ld\n", item - arr + 1);  // 輸出位置，從1開始
            } else {
                printf("Break your bridge!\n");
            }
        }

        free(arr);
    }
    return 0;
}