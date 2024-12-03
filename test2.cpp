#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

void turn(vector<vector<int>>& lst) {
    int n = lst.size();
    int m = lst[0].size();
    for (int i = 0; i < n / 2; i++) {
        swap(lst[i], lst[n - i - 1]);
    }
}

void twist(vector<vector<int>>& lst, int& n, int& m) {
    int n2 = lst.size();
    int m2 = lst[0].size();
    vector<vector<int>> result(m2, vector<int>(n2));
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++) {
            result[j][n2 - i - 1] = lst[i][j];
        }
    }
    lst = result;
    n = n2;
    m = m2;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<int>> r(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> r[i][j];
        }
    }

    vector<int> operations(s);
    for (int i = 0; i < s; i++) {
        cin >> operations[i];
    }

    for (int k = 0; k < s; k++) {
            if (operations[k] == 0) {
            twist(r, n, m);
        }
        if (operations[k] == 1) {
            turn(r);
        }
    }

    cout << r.size() << " " << r[0].size() << endl;
    for (const auto& row : r) {
        for (int j = 0; j < row.size(); j++) {
            if (j > 0)
                cout << " ";
            cout << row[j];
        }
        cout << endl;
    }

    return 0;
}
