#include <stdio.h>
int guard[][];
int tmp[];
int take_one(int ind) {
    for (int i = 0; i < n; i++)
        tmp[i] = wall[i];
    for (int i = guard[ind][0]; i <= guard[ind][1]; i++)
        tmp[i]--;

    int full = 0;
    for (int i = 0; i < n; i++) {
        if (tmp[i] > 0)
            full++;
    }
    int prefix[n];
}
int main() {
    for (int i = 0; i < q; i++) {
        for (int j = guard[i][0]; j <= guard[i][1]; j++) {
            wall[j]++;
        }
    }
    for (int i = 0; i < q; i++)
        ans = max(ans, take_one(i));
}
