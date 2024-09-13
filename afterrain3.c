#include <stddef.h>
typedef struct _NODE {
    char color[10];
    struct _NODE *next;
} Node;
void insert(Node **head, char *color, int n) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->color, color);
    newNode->next = NULL;
    Node *temp = *head;
    for (int i = 0; i < n && temp->next != NULL; i++)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

void erase1(Node **head, int n) {
    if (*head == NULL)
        return;
    Node *temp = *head;
    for (int i = 0; i < n - 1 && temp->next != NULL; i++)
        temp = temp->next;
    if (temp->next == NULL)
        return;
    Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}
void erase2(Node **head, char *color) {
    Node *temp = *head;
    Node *prev = NULL;

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
void reverse(Node **head, int a, int b) {
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