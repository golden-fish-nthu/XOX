#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

pair<int, char> countVowelAndLastVowel(const string &s) {
    int count = 0;
    char lastVowel = '0';
    for (char c : s) {
        if (isVowel(c)) {
            count++;
            lastVowel = c;
        }
    }
    return {count, lastVowel};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, unordered_map<char, int>> vowelMap;
    string s;

    while (n--) {
        cin >> s;
        auto [count, lastVowel] = countVowelAndLastVowel(s);
        vowelMap[count][lastVowel]++;
    }

    int pairFirst = 0, pairBoth = 0;

    for (const auto &countPair : vowelMap) {
        int tmp = 0;
        for (const auto &lastVowelPair : countPair.second) {
            tmp += lastVowelPair.second % 2;
            pairBoth += lastVowelPair.second / 2;
        }
        pairFirst += tmp / 2;
    }

    int ans = pairBoth <= pairFirst ? pairBoth : pairFirst + (pairBoth - pairFirst) / 2;
    cout << ans << "\n";

    return 0;
}