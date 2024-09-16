#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int r, n;
    vector<int> vec;
    auto ptr = vec.begin();
    cin >> r;
    cin >> n;
    vec.push_back(r);
    cin.ignore();  // Ignore the newline character after reading n
    for (int i = 0; i < n; i++) {
        string k;
        getline(cin, k);
        if (k[0] == 'i') {                       // insert
            int a = k[7] - '0', b = k[9] - '0';  // Convert char to int
            for (int i = 0; i < b; i++)
                vec.insert(++ptr, a);
        } else if (k[0] == 'e') {  // erase
            int c = k[6] - '0';
            for (auto i = ptr + 1; i != ptr + 1 + c; i++)  // Fixed the loop condition
                vec.erase(i);

        } else if (k[0] == 'm') {                // move
            int move_value = stoi(k.substr(5));  // Extract the move value
            int vec_size = vec.size();
            ptr += move_value % vec_size;  // Handle circular movement
            if (ptr < vec.begin())         // Handle moving beyond beginning
                ptr = vec.end() - 1;
            else if (ptr >= vec.end())  // Handle moving beyond end
                ptr = vec.begin();
        } else if (k[0] == 's') {  // show
            for (int i = 0; i < vec.size(); i++)
                cout << vec[i] << " ";  // Separate elements by space
            cout << endl;
        }
    }
}
