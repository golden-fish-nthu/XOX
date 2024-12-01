#include <iostream>
#include <vector>
using namespace std;

int dfs(int point, int parent, vector<vector<int>>& ns, vector<bool>& visit) {
    visit[point] = 1;                                        // 標記為訪問過
    for (int neighbor : ns[point]) {                         // 在鄰接表中找到所有鄰居
        if (!visit[neighbor]) {                              // 如果未訪問，開始 DFS
            int hasCycle = dfs(neighbor, point, ns, visit);  // point 是 neighbor 的父節點
            if (hasCycle != -1)                              // 如果有環，直接返回
                return hasCycle;

        } else if (neighbor != parent)  // 如果已訪問，且不是父節點，代表有環
            return neighbor;
    }
    return -1;
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;                   // n: 節點數
        vector<vector<int>> ns(n);  // 鄰接表
        for (int i = 0; i < n; i++) {
            int A, B;
            cin >> A >> B;
            ns[A].push_back(B);
            ns[B].push_back(A);
        }

        vector<bool> visit(n, 0);  // 初始化訪問陣列
        int hasCycle = dfs(0, -1, ns, visit);

        cout << hasCycle << endl;
    }
    return 0;
}
