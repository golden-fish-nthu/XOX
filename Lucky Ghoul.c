#include <stdio.h>
#include <stdlib.h>

int binarysearch(int* arr, int search, int n) {
    int low = 1;
    int high = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == search)
            return mid;
        else if (arr[mid] > search)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int n, q;
    while (scanf("%d %d", &n, &q) != EOF) {
        int* arr = (int*)malloc((n + 1) * sizeof(int));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < q; i++) {
            int ai;
            scanf("%d", &ai);
            int result = binarysearch(arr, ai, n);
            if (result == -1) {
                printf("Break your bridge!\n");
            } else {
                printf("%d\n", result);
            }
        }

        free(arr);
    }
    return 0;
}