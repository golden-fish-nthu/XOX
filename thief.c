
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000007
int count(char n[], int time, long long lenth_right, int x);
int main() {
    char input[1000];
    int numbers[100];
    int count = 5;
    scanf("%s", input);
    int lenth;
    long long totl = lenth = strlen(input);
    totl += count(input, (input[0] - 48), (lenth - 1), x);
}
int count(char n[], int time, long long lenth_right, int x) {
    int tmp = lenth_right * (time - 1);
}