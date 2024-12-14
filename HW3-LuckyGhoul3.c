#include <stdio.h>
#include <stdlib.h>
int bisearch(int* arr, int ai, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid potential overflow
        if (arr[mid] == ai)
            return mid;
        else if (arr[mid] > ai)
            return bisearch(arr, ai, low, mid - 1);
        else
            return bisearch(arr, ai, mid + 1, high);
    }
    return -1;  // Return -1 if not found
}
void cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, q;
    while (scanf("%d %d", &n, &q) != EOF) {
        int arr[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        for (int i = 0; i < q; i++) {
            int ai;
            scanf("%d", &ai);
            int result = bisearch(arr, ai, 0, n - 1);

            if (result == -1)
                printf("Break your bridge!\n");
            else
                printf("%d\n", result + 1);
        }
    }
}