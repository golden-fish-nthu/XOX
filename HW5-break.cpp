#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

set<int> mySet;

// 函式宣告
void print();
void rangeErase(int l, int r);
void findSum();

int main() {
    int n;
    cin >> n;        // 使用 cin 讀取輸入
    string command;  // 使用 string 類型的變數來儲存指令
    while (n--) {
        cin >> command;
        if (command == "insert") {
            int value;
            cin >> value;
            mySet.insert(value);  // 插入元素
        } else if (command == "print")
            print();  // 列出所有元素
        else if (command == "min") {
            if (!mySet.empty())
                cout << *mySet.begin() << endl;  // 輸出最小值 // 找出最小值
        } else if (command == "range_erase") {
            int l, r;
            cin >> l >> r;
            rangeErase(l, r);  // 刪除範圍內的元素
        } else if (command == "sum")
            findSum();  // 求和
    }

    return 0;
}

void print() {
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        if (it != mySet.begin())
            cout << " ";
        cout << *it;
    }
    cout << endl;
}

void rangeErase(int l, int r) {
    // 檢查範圍是否合理
    if (l > r)
        return;
    auto itLow = mySet.lower_bound(l);  // 找到範圍的起始位置
    auto itUp = mySet.upper_bound(r);   // 找到範圍的結束位置
    if (itLow != itUp)                  // 確保範圍內有元素
        mySet.erase(itLow, itUp);       // 刪除範圍 [itLow, itUp)
}

void findSum() {
    int sum = 0;
    for (int i : mySet)
        sum += i;
    cout << sum << endl;  // 輸出總和
}
