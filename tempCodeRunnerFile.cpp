#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using namespace std;

set<int> mySet;

// 函式宣告
void insert(int value);
void print();
void findMin();
void rangeErase(int l, int r);
void findSum();

int main() {
    int n;
    cin >> n;
    string command;

    for (int i = 0; i < n; ++i) {
        cin >> command;
        if (command == "insert") {
            int value;
            cin >> value;
            insert(value);  // 插入元素
        } else if (command == "print") {
            print();  // 列出所有元素
        } else if (command == "min") {
            findMin();  // 找出最小值
        } else if (command == "range_erase") {
            int l, r;
            cin >> l >> r;
            rangeErase(l, r);  // 刪除範圍內的元素
        } else if (command == "sum") {
            findSum();  // 求和
        }
    }

    return 0;
}
void insert(int value) {
    mySet.insert(value);
}
void print() {
    cout << "----";
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void findMin() {
    if (!mySet.empty()) {
        cout << "----" << endl;
        return;
    }
    cout << *mySet.begin() << endl;
}

void rangeErase(int l, int r) {
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        if (*it >= l && *it <= r) {
            mySet.erase(it);
        }
    }
}

void findSum() {
    cout << "----";
    int sum = 0;
    for (auto it = mySet.begin(); it != mySet.end(); ++it) {
        sum += *it;
    }
    cout << sum << endl;
}