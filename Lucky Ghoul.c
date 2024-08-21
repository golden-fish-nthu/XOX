#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
void binarysearch(int *arr, int search, int n) {
    int low = 1;
    int high = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] = search)
            return mid;
        else if (arr[mid] > search)
            high = mid - 1;
        else if (arr[mid] < search)
            low = mid + 1;
    }
    return -100;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
    }
    return 0;
}