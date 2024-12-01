#include <stdio.h>
#include <stdlib.h>
int bisearch(int* arr, int ai, int n) {
    int low = 0;
    int high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == ai)
            return mid;
        else if (arr[mid] > ai)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;  // Return -1 if not found
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
            int result = bisearch(arr, ai, n);
            if (result == -1)
                printf("Break your bridge!\n");
            else
                printf("%d\n", result + 1);
        }
    }
}