#include <stdio.h>
int sequ[200005];

long long sigma(long long r) {
    return (r * (r + 1)) / 2;
}

typedef struct Pair {
    int first;
    int second;
} Pair;

Pair dec(int m);
Pair dec2(int m);

int main() {
    int r;
    scanf("%d", &r);
    for (int i = 0; i < r; i++) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < n; ++i)
            sequ[i] = 1;
        Pair tmp = dec(m);
        if (tmp.first <= n) {
            if (tmp.second == 0) {
                int k1 = tmp.first;
                for (int i = 0; i < k1; i++)
                    sequ[i] = k;
            } else {
                int k1 = tmp.first;
                for (int i = 0; i < k1; i++)
                    sequ[i] = k;
                int last = tmp.second;
                Pair k2 = dec2(last);
                for (int i = 0; i < k2.first; i++)
                    sequ[i] = k * 2;
                for (int i = k2.first + 1; i < k2.first + 1 + k2.second; i++)
                    sequ[i] = k * 2;
            }
        } else {
            printf("-1\n");
            continue;
        }
        for (int i = 0; i < n; ++i) {
            printf("%d ", sequ[i]);
        }
        putchar('\n');
    }
    return 0;
}

Pair dec(int m) {
    int i = 1;
    if (m == 0) {
        Pair tmp = {0, 0};
        return tmp;
    }
    while (sigma(i) < m)
        ++i;
    if (sigma(i) == m) {
        Pair tmp = {i, 0};
        return tmp;
    } else {
        int r = sigma(i) - m;
        Pair tmp = {i, r};
        return tmp;
    }
}

Pair dec2(int m) {
    int i = 1;
    while (sigma(i) < m)
        ++i;
    if (sigma(i) == m) {
        Pair tmp = {i, 0};
        return tmp;
    } else {
        int r = m - sigma(i - 1);
        Pair tmp3 = dec2(r);
        Pair tmp = {i, tmp3.first};
        return tmp;
    }
}
