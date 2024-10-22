#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n, q, x;
    scanf("%d", &n);
    int arr[1000000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), compare);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);
        int index = binary_search(arr, n, x);
        if (index == -1) {
            printf("0\n");
        } else {
            int count = 1;
            int left = index - 1;
            while (left >= 0 && arr[left] == x)
                count++, left--;
            int right = index + 1;
            while (right < n && arr[right] == x)
                count++, right++;
            printf("%d\n", count);
        }
    }
    return 0;
}