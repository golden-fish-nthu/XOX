#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 将节点插入链表头部
Node* insertAtHead(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    return newNode;
}

// 打印链表
void printList(Node* head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Node* head = NULL;

    // 建立初始链表
    for (int i = n; i >= 1; i--) {
        head = insertAtHead(head, i);
    }

    // 处理请求
    for (int i = 0; i < m; i++) {
        int request;
        scanf("%d", &request);

        Node* prev = NULL;
        Node* curr = head;

        // 找到请求指定的节点
        while (curr != NULL && curr->data != request) {
            prev = curr;
            curr = curr->next;
        }

        // 如果请求指定的节点不在链表头部，则将其移动到链表头部
        if (prev != NULL && curr != NULL) {
            prev->next = curr->next;
            curr->next = head;
            head = curr;
        }
    }

    // 输出链表
    printList(head);

    // 释放内存
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
