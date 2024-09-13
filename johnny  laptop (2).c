#include <stdio.h>
#define ll long long
void quick_sort(ll arr[], ll first_index, ll last_index) {
    // 宣告索引變數
    ll pivotIndex, temp, index_a, index_b;

    if (first_index < last_index) {
        // 以第一個元素作為基準
        pivotIndex = first_index;
        index_a = first_index;
        index_b = last_index;

        // 以遞增方式排序
        while (index_a < index_b) {
            while (arr[index_a] <= arr[pivotIndex] && index_a < last_index) {
                index_a++;
            }
            while (arr[index_b] > arr[pivotIndex]) {
                index_b--;
            }

            if (index_a < index_b) {
                // 交換元素
                temp = arr[index_a];
                arr[index_a] = arr[index_b];
                arr[index_b] = temp;
            }
        }

        // 交換基準元素與 index_b 元素
        temp = arr[pivotIndex];
        arr[pivotIndex] = arr[index_b];
        arr[index_b] = temp;

        // 遞迴呼叫快速排序法函數
        quick_sort(arr, first_index, index_b - 1);
        quick_sort(arr, index_b + 1, last_index);
    }
}
int main() {
    int n = 5;
    ll totl = 0;
    ll k;
    scanf("%d%lld", &n, &k);
    ll arr[40];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        ll tmp = arr[i];
        while (tmp < k) {
            for (int j = i + 1; j < n; j++) {
                tmp = tmp + arr[j];
            }
        }
    }
}