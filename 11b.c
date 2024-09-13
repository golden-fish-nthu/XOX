#include <stdio.h>
#include <stdlib.h>

// 結構體用來存儲每個商品的今天價格，明天價格和價格差異
typedef struct {
    int a;     // 今天價格
    int b;     // 明天價格
    int diff;  // 差異 a - b
} Item;

// 比較函數，按價格差異從小到大排序
int compare(const void* p1, const void* p2) {
    Item* item1 = (Item*)p1;
    Item* item2 = (Item*)p2;
    return (item1->diff - item2->diff);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    Item items[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].a);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].b);
        items[i].diff = items[i].a - items[i].b;
    }

    // 按價格差異排序
    qsort(items, n, sizeof(Item), compare);

    long long total_cost = 0;
    // 在第一天購買前 k 件商品
    for (int i = 0; i < k; i++) {
        total_cost += items[i].a;
    }
    // 在剩下的天數購買剩餘的商品
    for (int i = k; i < n; i++) {
        total_cost += (items[i].diff <= 0) ? items[i].a : items[i].b;
    }

    printf("%lld\n", total_cost);

    return 0;
}