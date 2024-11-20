#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct CatToast {
    int x, y;
    bool visited = false;
};

vector<CatToast> catToasts;
int n, r;

int distanceSquared(CatToast a, CatToast b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int dfs(int index) {
    catToasts[index].visited = true;
    int count = 1;

    for (int i = 0; i < n; i++)
        if (!catToasts[i].visited && distanceSquared(catToasts[index], catToasts[i]) <= r * r)
            count += dfs(i);
    return count;
}

int main() {
    int blackHoles = 0;
    int remainingCatToasts = 0;
    cin >> n >> r;

    catToasts.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> catToasts[i].x >> catToasts[i].y;
        catToasts[i].visited = false;
    }

    for (int i = 0; i < n; ++i) {
        if (!catToasts[i].visited) {
            int groupSize = dfs(i);
            if (groupSize > 1)
                blackHoles++;  // 群組中的貓吐司數量大於1，形成一個黑洞
            else
                remainingCatToasts++;  // 群組只有1隻貓吐司，視為孤立
        }
    }

    cout << remainingCatToasts << " " << blackHoles << endl;
    return 0;
}
