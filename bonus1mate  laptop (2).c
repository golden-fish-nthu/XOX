#include <stdio.h>
#include <stdlib.h>
int a[200005];
int n, k;
int found = 0;
long long m;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int fakegcd(int a, int b) {
    if (a == b)
        return a;
    if (a != 1 && b > a)
        return a;
    if (b != 1 && a > b)
        return b;
    if (a == 1 || b == 1)
        return 1;
}
int How_many_gcd(int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int current_gcd = a[i];
        for (int j = i; j < n; j++) {
            current_gcd = fakegcd(current_gcd, a[j]);
            if (current_gcd == k) {
                count++;
            }
        }
    }
    return count;
}
void array(int seq[], int index) {
    if (found)
        return;
    if (index == n) {
        if (How_many_gcd(n) == m) {
            for (int i = 0; i < n; i++) {
                printf("%d ", seq[i]);
            }
            printf("\n");
            // printf("[%d]\n", How_many_gcd(n));
            found = 1;
        }
        return;
    }

    seq[index] = 2 * k;
    array(seq, index + 1);

    seq[index] = 1;
    array(seq, index + 1);

    seq[index] = k;
    array(seq, index + 1);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        found = 0;
        scanf("%d %lld %d", &n, &m, &k);
        /*n = 5;
        m = 9;
        k = 2;*/
        for (int i = 0; i < n; i++) {
            a[i] = k;
        }
        array(a, 0);
        if (found == 0)
            printf("-1\n");
        // printf("%d\n", How_many_gcd(n));
    }
    return 0;
}
