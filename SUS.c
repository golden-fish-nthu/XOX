#include <math.h>
#include <stdio.h>

// Function to count nodes with only one child
int countOneChildNodes(int pre[], int post[], int n) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (pre[i + 1] != post[i]) {
            printf("Node with one child: %d\n", pre[i + 1]);
            count++;
        }
    }
    return count;
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        int pre[n], post[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &pre[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &post[i]);
        }
        int result = pow(2, countOneChildNodes(pre, post, n));

        printf("%d\n", result);
    }
    return 0;
}