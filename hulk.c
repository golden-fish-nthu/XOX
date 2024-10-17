#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL 1000000000

typedef struct {
    int key;
    int count;
} HashNode;

typedef struct {
    HashNode* nodes;
    int size;
} HashMap;

unsigned int hash(int key, int size) {
    return (unsigned int)key % size;
}

HashMap* createHashMap(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->nodes = (HashNode*)calloc(size, sizeof(HashNode));
    map->size = size;
    return map;
}

void insert(HashMap* map, int key) {
    unsigned int index = hash(key, map->size);
    while (map->nodes[index].count != 0 && map->nodes[index].key != key) {
        index = (index + 1) % map->size;
    }
    if (map->nodes[index].count == 0) {
        map->nodes[index].key = key;
    }
    map->nodes[index].count++;
}

int getCount(HashMap* map, int key) {
    unsigned int index = hash(key, map->size);
    while (map->nodes[index].count != 0) {
        if (map->nodes[index].key == key) {
            return map->nodes[index].count;
        }
        index = (index + 1) % map->size;
    }
    return 0;
}

void freeHashMap(HashMap* map) {
    free(map->nodes);
    free(map);
}

int main() {
    int n, q, x;

    // 讀取序列長度 n
    scanf("%d", &n);

    // 初始化哈希表
    HashMap* map = createHashMap(n * 2);  // 使用兩倍大小的哈希表來減少碰撞

    // 讀取序列 a 並計算每個數字的出現次數
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(map, x);
    }

    // 讀取查詢數量 q
    scanf("%d", &q);

    // 處理每個查詢
    for (int i = 0; i < q; i++) {
        scanf("%d", &x);
        printf("%d\n", getCount(map, x));
    }

    // 釋放動態分配的記憶體
    freeHashMap(map);

    return 0;
}