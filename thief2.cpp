#include <iostream>
#include <string>
using namespace std;
int move_cut(string s, int pos, int x);
int totl = 1;
int main() {
    string test = "133321333";

    totl = test.length();
    int final = move_cut(test, 24, 0);
    cout << "totl = " << totl;
}
int move_cut(string s, int time, int x) {
    if (time == x)
        return 0;
    else {
        int n = (s[0] - '0');
        string right = s.substr(1);
        cout << "right = " << right << endl;
        string newone;
        for (int i = 0; i < n; ++i) {
            newone += right;
        }
        cout << "newone = " << newone << endl;
        int lenth = (newone.length() - right.length()) % (1000000007);
        totl += lenth;
        return move_cut(newone, time, x + 1);
    }
}