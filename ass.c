#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int values[] = {5, 20, 29, 32, 63};
    int key = 32;

    // Sort the array using qsort
    qsort(values, 5, sizeof(int), compare);

    // Perform binary search using bsearch
    int* item = (int*)bsearch(&key, values, 5, sizeof(int), compare);

    if (item != NULL) {
        printf("Found item = %d\n", *item);
    } else {
        printf("Item not found\n");
    }

    return 0;
}