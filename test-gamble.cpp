#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> rollDice(string sequence) {
    vector<int> faces;
    faces.push_back(1);  // 上
    faces.push_back(6);  // 下
    faces.push_back(3);  // 左
    faces.push_back(4);  // 右
    faces.push_back(2);  // 前
    faces.push_back(5);  // 後
    for (char& direction : sequence) {
        int temp;
        switch (direction) {
            case 'F':  // 向前滾動
                temp = faces[0];
                faces[0] = faces[5];
                faces[5] = faces[1];
                faces[1] = faces[4];
                faces[4] = temp;
                break;
            case 'B':  // 向後滾動
                temp = faces[0];
                faces[0] = faces[4];
                faces[4] = faces[1];
                faces[1] = faces[5];
                faces[5] = temp;
                break;
            case 'L':  // 向左滾動
                temp = faces[0];
                faces[0] = faces[3];
                faces[3] = faces[1];
                faces[1] = faces[2];
                faces[2] = temp;
                break;
            case 'R':  // 向右滾動
                temp = faces[0];
                faces[0] = faces[2];
                faces[2] = faces[1];
                faces[1] = faces[3];
                faces[3] = temp;
                break;
        }
    }
    return faces;
}
int main() {
    string nam1, nam2, seq1, seq2;
    cin >> nam1 >> seq1 >> nam2 >> seq2;

    vector<int> result1 = rollDice(seq1);
    vector<int> result2 = rollDice(seq2);

    cout << nam1 << " " << result1[0] << " " << result1[1] << " " << result1[2] << " " << result1[3] << " " << result1[4] << " " << result1[5] << endl;
    cout << nam2 << " " << result2[0] << " " << result2[1] << " " << result2[2] << " " << result2[3] << " " << result2[4] << " " << result2[5] << endl;
    int r = result1[1] - result2[1];
    cout << r << endl;
    if (r == 0) {
        cout << "Tie" << endl;
    } else if (r > 0) {
        cout << nam1 << endl;
    } else if (r < 0) {
        cout << nam2 << endl;
    }
}
