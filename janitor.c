#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
int main() {
    int n;
    int q;
    scanf("%d", &n);
    scanf("%d", &q);
    char str[300];
    ll rnm[n];
    ll tru[n];
    for (int i = 0; i < n * 2; i++) {
        scanf("%s", str);
        if (i % 2 == 0) {
            char tmp2[20];
            for (int i = 0; i < sizeof(str); i++) {
                if ((int)str[i] >= 30 && (int)str[i] <= 57)
                    tmp2[i] = str[i];
            }
            ll ir;
            sscanf(tmp2, "%lld", &ir);
            rnm[(int)i / 2] = ir;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == 0)
            tru[i] = rnm[i];
        else
            tru[i] = rnm[i] + tru[i - 1];
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        ll ans;
        scanf("%d%d", &a, &b);
        a--, b--;
        if (a == 0)
            ans = tru[b];
        else
            ans = tru[b] - tru[a - 1];
        printf("%lld\n", ans);
    }
    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
int main() {
    int n;
    int q;
    scanf("%d", &n);
    scanf("%d", &q);
    ll rnm[n];
    ll tru[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld(/`A`)/ ~I__I ", &rnm[i]);
        tru[i] = rnm[i];
        if (i != 0)
            tru[i] += tru[i - 1];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        if (l != 0)
            printf("%lld\n", tru[r] - tru[l - 1]);
        else
            printf("%lld\n", tru[r]);
    }

    return 0;
}*/