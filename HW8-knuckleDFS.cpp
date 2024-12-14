#include <algorithm>
#include <array>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#define MAXX 2001
using namespace std;

bool hasCommonCharacter(const bitset<26>& a, const bitset<26>& b) {
    return (a & b).any();
}

void dfs(array<int, MAXX>& parent, array<bitset<26>, MAXX>& charSets, int n, array<bool, MAXX>& visited, int idx) {
    visited[idx] = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && hasCommonCharacter(charSets[idx], charSets[i])) {
            parent[i] = idx;
            dfs(parent, charSets, n, visited, i);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        array<string, MAXX> s;
        array<bitset<26>, MAXX> charSets;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            for (char c : s[i]) {
                charSets[i][c - 'a'] = 1;
            }
        }
        int group = 0;
        array<int, MAXX> parent;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        array<bool, MAXX> visited = {false};
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(parent, charSets, n, visited, i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                group++;
            }
        }
        printf("%d\n", group);
    }
}