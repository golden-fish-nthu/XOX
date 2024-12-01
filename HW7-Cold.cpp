#include <iostream>
#include <set>
#include <string>
#include <vector>
#define MAX_SIZE 200001
using namespace std;

struct cmp {
    bool operator()(const string &a, const string &b) const {
        return (a.size() != b.size()) ? (a.size() < b.size()) : (a < b);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // 使用 multiset 儲存數字，並維護排序
    multiset<string, cmp> sortedNumbers;
    // 使用 C-style array 儲存數字，支援 find idx 操作
    string sequence[MAX_SIZE];
    int sequenceSize = 0; // To keep track of the current size of the array

    while (n--) {
        string command;
        cin >> command;

        if (command == "insert") {
            string num;
            cin >> num;
            sortedNumbers.insert(num);
            if (sequenceSize < MAX_SIZE)
                sequence[sequenceSize++] = num;

        } else if (command == "min") {
            if (!sortedNumbers.empty())
                cout << *sortedNumbers.begin() << "\n";

        } else if (command == "max") {
            if (!sortedNumbers.empty())
                cout << *sortedNumbers.rbegin() << "\n";

        } else if (command == "amount") {
            string num;
            cin >> num;
            cout << sortedNumbers.count(num) << "\n";
        } else if (command == "find") {
            int idx;
            cin >> idx;
            if (idx > 0 && idx <= sequenceSize)
                cout << sequence[idx - 1] << "\n";
        }
    }

    return 0;
}
