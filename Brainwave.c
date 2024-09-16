#include <stdio.h>
int main() {
    int t = 1, a = 8, b = 9, time;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int xo;
        int arr[100];
        scanf("%d %d", &a, &b);
        arr[0] = 0;
        xo = 0;
        for (int i = 1; i < a; i++) {
            arr[i] = i;
            xo = xo ^ arr[i];
            // printf("xo = %d\n", xo);
        }
        time = a;
        // printf("xo^b= %d\n", xo ^ b);
        if (xo == b)
            printf("%d\n", time);
        else if (xo != b && (xo ^ b) != a)
            printf("%d\n", time + 1);
        else
            printf("%d\n", time + 2);
    }
    return 0;
}