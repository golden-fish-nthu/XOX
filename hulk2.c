#include <stdio.h>
#include <stdlib.h>

// 定義鏈表節點的結構
typedef struct Node {
    int key;           // 數字
    int value;         // 出現次數
    struct Node *next; // 指向下一個節點
} Node;

// 哈希表大小
#define HASH_SIZE 100003

// 哈希表，每個槽位都是一個鏈表的頭指針
Node *hashTable[HASH_SIZE];

// 哈希函數
unsigned int hashFunction(int key) {
    return abs(key) % HASH_SIZE;
}

// 插入或更新哈希表中的數字
void insert(int key) {
    unsigned int hashIndex = hashFunction(key);
    Node *current = hashTable[hashIndex];

    // 在對應的鏈表中查找該數字
    while (current != NULL) {
        if (current->key == key) {
            // 如果數字已經存在，出現次數加1
            current->value++;
            return;
        }
        current = current->next;
    }

    // 如果數字不存在，創建一個新節點並插入鏈表頭部
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 1;
    newNode->next = hashTable[hashIndex];
    hashTable[hashIndex] = newNode;
}

// 查找某個數字的出現次數
int search(int key) {
    unsigned int hashIndex = hashFunction(key);
    Node *current = hashTable[hashIndex];

    // 遍歷鏈表查找該數字
    while (current != NULL) {
        if (current->key == key)
            return current->value;
        current = current->next;
    }

    // 如果沒有找到，返回 0
    return 0;
}

int main() {
    // 初始化哈希表
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // 讀取輸入
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        insert(a); // 插入數字
    }

    // 處理查詢
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        printf("%d\n", search(x)); // 查詢數字出現次數
    }

    return 0;
}
