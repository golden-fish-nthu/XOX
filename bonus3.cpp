#include <iostream>
using namespace std;
int cup[20] = {3, 2, 2, 1, 1};
long long sigma(long long r) {
    return (r * (r + 1)) / 2;
}
int count(int cof, int tar) {
    /*for (int i = 0; i < cof; i++) {
        cin >> cup[i];
    }*/
    int days = cof;
    int totl = 0;
    for (int i = 0; i < days; i++) {
        totl += cup[i];
    }
    if (totl < tar)
        return -1;  // If we cannot reach the target
    else {
        int tmp = 0;
        while (sigma(tmp) < (totl - tar)) {
            days--;
            tmp++;
        }
        return days;
    }
}

int main() {
    int t = 1;
    // cin >> t;

    while (t--) {
        int cof = 5, tar = 8;
        // cin >> cof >> tar;
        int ans = count(cof, tar);
        cout << "ans:" << ans << endl;
    }

    return 0;
}
