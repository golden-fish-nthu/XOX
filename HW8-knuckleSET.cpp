#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
#define MAXX 2001

using namespace std;

bool sameGroup(const unordered_set<char>& a, const unordered_set<char>& b) {
    for (char c : a) {
        if (b.count(c)) {
            return true;
        }
    }
    return false;
}

// 合併兩個集合
void unionSets(int a, int b, array<int, MAXX>& parent) {
    int rootA = a;  // 找到a的根
    while (parent[rootA] != rootA)
        rootA = parent[rootA];

    int rootB = b;  // 找到b的根
    while (parent[rootB] != rootB)
        rootB = parent[rootB];
    // 如果a和b的根不同，將b的根指向a的根
    if (rootA != rootB)
        parent[rootB] = rootA;
}
// void unionSets()
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_set<char> s[MAXX];
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            for (char c : str)
                s[i].insert(c);
        }
        array<int, MAXX> parent;
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sameGroup(s[i], s[j]))
                    unionSets(i, j, parent);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                count++;

        cout << count << endl;
    }
}