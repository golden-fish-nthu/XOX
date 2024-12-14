#include <stdio.h>
#include <stdlib.h>

struct _Node {
    int number;
    struct _Node* next;
};

typedef struct _Node Node;

Node* createList(int n) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->number = n;
    head->next = NULL;
    return head;
}

void freeList(Node* head) {
    free(head);
}

int solveJosephus(Node** head, int step) {
    int n = (*head)->number;
    int s = 0;
    for (int i = 2; i <= n; i++) {
        s = (s + step) % i;
    }
    return s + 1;
}

int main() {
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF) {
        Node* head = createList(n);
        printf("%d\n", solveJosephus(&head, k));
    }
    return 0;
}