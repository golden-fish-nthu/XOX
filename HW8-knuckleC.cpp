#include <stdio.h>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
#define MAXX 2001
using namespace std;
bool find(const bitset<MAXX> s[26], int i, int j) {
    for (int k = 0; k < 26; k++)
        if (s[k][i] && s[k][j])
            return true;
    return false;
}

void dfs(vector<int>& parent, const bitset<MAXX> s[26], int n, vector<bool>& visited, int idx) {
    visited[idx] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && find(s, idx, i)) {
            parent[i] = idx;
            dfs(parent, s, n, visited, i);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bitset<MAXX> s[26];  // Initialize bitset matrix
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            for (char c : str)
                s[c - 'a'][i] = true;
        }
        int group = 0;
        vector<int> parent(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(parent, s, n, visited, i);

        for (int i = 0; i < n; i++)
            if (parent[i] == i)
                group++;

        cout << group << endl;
    }
}