#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 2000
#define MAXLEN 1000

// 並查集結構
typedef struct UnionFind {
    int parent[MAXN];
    int rank[MAXN];
} UnionFind;

void initUnionFind(UnionFind* uf, int n) {
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }
}

int find(UnionFind* uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]);  // 路徑壓縮
    }
    return uf->parent[x];
}

void unionSets(UnionFind* uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);

    if (rootX != rootY) {
        if (uf->rank[rootX] > uf->rank[rootY]) {
            uf->parent[rootY] = rootX;
        } else if (uf->rank[rootX] < uf->rank[rootY]) {
            uf->parent[rootX] = rootY;
        } else {
            uf->parent[rootY] = rootX;
            uf->rank[rootX]++;
        }
    }
}

int findGroups(char strings[][MAXLEN], int n) {
    UnionFind uf;
    initUnionFind(&uf, n);

    int char_map[26] = {0};

    // 遍歷每個字符串
    for (int i = 0; i < n; i++) {
        int len = strlen(strings[i]);
        int unique[26] = {0};

        // 遍歷字符串中的每個字符
        for (int j = 0; j < len; j++) {
            int c = strings[i][j] - 'a';
            if (!unique[c]) {
                unique[c] = 1;
                if (char_map[c] > 0) {
                    unionSets(&uf, i, char_map[c] - 1);
                } else {
                    char_map[c] = i + 1;
                }
            }
        }
    }

    // 計算連通分量數量
    int numGroups = 0;
    int seen[MAXN] = {0};

    for (int i = 0; i < n; i++) {
        int root = find(&uf, i);
        if (!seen[root]) {
            seen[root] = 1;
            numGroups++;
        }
    }

    return numGroups;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char strings[MAXN][MAXLEN];
        for (int i = 0; i < n; i++) {
            scanf("%s", strings[i]);
        }

        int result = findGroups(strings, n);
        printf("%d\n", result);
    }

    return 0;
}
