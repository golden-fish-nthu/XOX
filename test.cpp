#include <iostream>
using namespace std;

int main() {
    float s = 0;
    const int n = 40000;
    for (int i = 0; i < 12; i++) {
        s = s * 1.05 + n;
        cout << "The final amount after " << i + 1 << " months will be: $" << s << endl;
    }

    return 0;
}