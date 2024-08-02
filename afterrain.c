#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _NODE {
    char color[10];
    struct _NODE *next;
} Node;

void show(Node **head) {
    Node *temp = (*head)->next;
    while (temp != NULL) {
        printf("%s ", temp->color);
        temp = temp->next;
    }
    printf("\n");
}

void insert(Node **head, char *color, int n) {
    Node *ptr = *head;
    for (int i = 0; ptr->next != NULL && i < n; i++)
        ptr = ptr->next;

    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->color, color);
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void erase1(Node **head, int n) {
    Node *ptr = *head, *prev = NULL;
    if (ptr->next == NULL)
        return;
    for (int i = 0; ptr->next != NULL && i < n; i++) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
}

void erase2(Node **head, char *color) {
    Node *ptr = *head, *prev = NULL;
    while (ptr->next != NULL) {
        if (!strcmp(ptr->color, color)) {
            prev->next = ptr->next;

            ptr = prev;
        }
        prev = ptr;
        ptr = ptr->next;
    }
}

void reverse(Node **head_ref, int pos1, int pos2) {
    pos1++, pos2++;
    if (pos1 == pos2)
        return; // 相同位置無需交換
    Node *prev1 = NULL, *curr1 = *head_ref, *prev2 = NULL, *curr2 = *head_ref, *temp;
    // 找到 pos1 節點和其前驅節點
    for (int i = 1; curr1 && i < pos1; i++) {
        prev1 = curr1;
        curr1 = curr1->next;
    }
    // 找到 pos2 節點和其前驅節點
    for (int i = 1; curr2 && i < pos2; i++) {
        prev2 = curr2;
        curr2 = curr2->next;
    }
    // 如果任一位置超出鏈表長度
    if (!curr1 || !curr2)
        return;
    // 如果 pos1 節點的前驅節點不為空
    if (prev1)
        prev1->next = curr2;
    else
        *head_ref = curr2;
    // 如果 pos2 節點的前驅節點不為空
    if (prev2)
        prev2->next = curr1;
    else
        *head_ref = curr1;
    // 交換兩個節點的 next 指針
    temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}

int n;
char buf[100];
int num1, num2;
Node *head;

int main() {
    head = (Node *)malloc(sizeof(Node)); // create an empty node
    memset(head->color, '\0', sizeof(head->color));
    head->next = NULL;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", buf);
        if (!strcmp(buf, "insert")) {
            scanf("%s%d", buf, &num1);
            insert(&head, buf, num1); // insert <color> <dest>
        } else if (!strcmp(buf, "erase1")) {
            scanf("%d", &num1);
            erase1(&head, num1); // erase1 <dest>
        } else if (!strcmp(buf, "erase2")) {
            scanf("%s", buf);
            erase2(&head, buf); // erase2 <color>
        } else if (!strcmp(buf, "reverse")) {
            scanf("%d%d", &num1, &num2);
            reverse(&head, num1, num2); // reverse <dest1> <dest2>
        } else if (!strcmp(buf, "show")) {
            show(&head);
        }
    }
    return 0;
}
