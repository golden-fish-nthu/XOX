#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE {
    char color[10];
    struct _NODE* next;
} Node;

void show(Node** head) {
    Node* now = (*head)->next;
    while (now != NULL) {
        printf("%s ", now->color);
        now = now->next;
    }
    puts("");
}

void insert(Node** head, char* color, int n) {
    n++;
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->color, color);
    newNode->next = NULL;

    Node* temp = *head;
    for (int i = 1; i < n && temp->next != NULL; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void erase1(Node** head, int n) {
    if (*head == NULL)
        return;
    Node* temp = *head;
    if (n == 1) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    for (int i = 1; i < n && temp->next != NULL; i++)
        temp = temp->next;
    if (temp->next == NULL)
        return;
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

void erase2(Node** head, char* color) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->color, color) == 0) {
            if (prev == NULL) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}
void reverse(Node** head, int a, int b) {
    if (a == b)
        return;
    a++, b++;
    Node *prev = NULL, *current = *head, *next = NULL;
    Node *startPrev = NULL, *endNext = NULL;
    Node *start = NULL, *end = NULL;
    int i;

    for (i = 1; current != NULL && i < a; i++) {
        startPrev = current;
        current = current->next;
    }
    start = current;

    for (; current != NULL && i <= b; i++) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    end = prev;
    endNext = current;

    if (startPrev != NULL) {
        startPrev->next = end;
    } else {
        *head = end;
    }
    start->next = endNext;
}

int n;
char buf[100];
int num1, num2;
Node* head;

int main() {
    head = (Node*)malloc(sizeof(Node));  // create an empty node
    memset(head->color, '\0', sizeof(head->color));
    head->next = NULL;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", buf);
        if (!strcmp(buf, "insert")) {
            scanf("%s%d", buf, &num1);
            insert(&head, buf, num1);  // insert <color> <dest>
        } else if (!strcmp(buf, "erase1")) {
            scanf("%d", &num1);
            erase1(&head, num1);  // erase1 <dest>
        } else if (!strcmp(buf, "erase2")) {
            scanf("%s", buf);
            erase2(&head, buf);  // erase2 <color>
        } else if (!strcmp(buf, "reverse")) {
            scanf("%d%d", &num1, &num2);
            reverse(&head, num1, num2);  // reverse <dest1> <dest2>
        } else if (!strcmp(buf, "show")) {
            show(&head);
        }
    }
    return 0;
}
