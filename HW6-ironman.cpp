#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define MAX 1000
#define INF 1e9
#define Point pair<int, int>
#define x first
#define y second

char grid[MAX][MAX];
int dist[MAX][MAX];
int dx[] = {0, 0, 1, -1}; // 四個方向 (右, 左, 下, 上)
int dy[] = {1, -1, 0, 0};
using namespace std;

int bfs(int n, int m, vector<Point> &targets) {
    queue<Point> q;
    q.push(targets[0]);
    dist[targets[0].x][targets[0].y] = 0;
    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // 判斷是否超出邊界或已拜訪過
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == 'C' || dist[nx][ny] != INF)
                continue;

            dist[nx][ny] = dist[current.x][current.y] + 1;
            q.push({nx, ny});
        }
    }

    // 計算覆蓋所有目標的最遠距離
    int maxDist = 0;
    for (Point target : targets) {
        if (dist[target.x][target.y] == INF)
            return -1; // 有無法到達的點
        maxDist = max(maxDist, dist[target.x][target.y]);
    }
    return maxDist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Point> targets;
    targets.push_back({0, 0});
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'I')
                targets[0] = {i, j};
            else if (grid[i][j] == 'T')
                targets.push_back({i, j});
        }
    }

    // 初始化距離陣列
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dist[i][j] = INF;

    int result = bfs(n, m, targets);
    cout << result << endl;

    return 0;
}