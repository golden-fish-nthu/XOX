#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#define MAX 1001
#define INF 1e9
#define point tuple<int, int, int>
using namespace std;
char map[MAX][MAX];
queue<point> q;
int n, m, d = 0;
int ans = 0;
int bfs() {
    while (!q.empty()) {
        int x, y, cnt;
        tie(x, y, cnt) = q.front();
        q.pop();
        if (x < 0 || x >= n || y < 0 || y >= m)
            continue;
        if (map[x][y] == 'T') {
            d--;
            ans = max(ans, cnt);
        }
        if (map[x][y] == 'I') {
            map[x][y] = 'C';
        }
        if (map[x][y] == 'C') {
            continue;
        }
        if (x + 1 < n)
            q.push({x + 1, y, cnt + 1});
        if (x - 1 >= 0)
            q.push({x - 1, y, cnt + 1});
        if (y + 1 < m)
            q.push({x, y + 1, cnt + 1});
        if (y - 1 >= 0)
            q.push({x, y - 1, cnt + 1});
    }
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'I')
                q.push({i, j, 0});
            else if (map[i][j] == 'T')
                d++;
        }
    }

    int result = bfs();
    if (d != 0)
        cout << -1 << endl;
    else
        cout << result << endl;

    return 0;
}