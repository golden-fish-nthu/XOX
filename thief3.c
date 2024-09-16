#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int totl = 1;

int move_cut(char* s, int pos, int x);

int main() {
    int r;
    scanf("%d", &r);
    for (int i = 0; i < r; i++) {
        int x;
        scanf("%d", &x);
        char test[501] = "";
        scanf("%s", test);
        int len = strlen(test);
        totl = len;
        int final = move_cut(test, x, 0);
        printf("totl = %d\n", totl);
    }

    return 0;
}

int move_cut(char* s, int time, int x) {
    // printf("x = %d\n", x);
    if (time == x)
        return 0;
    else {
        int n = s[0] - '0';
        char right[MAX_LEN] = "";
        strcpy(right, s + 1);
        char newone[MAX_LEN] = "";
        int i, j;
        for (i = 0; i < n; ++i) {
            strcat(newone, right);
        }
        // printf("newone = %s\n", newone);
        int lenth = (strlen(newone) - strlen(right)) % 1000000007;
        totl += lenth;
        // printf("totl = %d\n", totl);
        return move_cut(newone, time, x + 1);
    }
}