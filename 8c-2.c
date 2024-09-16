#include <stdio.h>
#define ll long long
long long calculateMatches(long long students) {
    long long matches = 0;
    while (students > 1) {
        if (students % 2 == 0) {
            matches += students / 2;
            students /= 2;
        } else {
            matches += students * (students - 1) / 2;
            break;
        }
    }
    return matches;
}

// 函數原型宣告

// 函數定義：計算最小學生數量
int findMinimumStudents(int n) {
    // 如果比賽數量為1，則至少需要2名學生
    if (n == 1)
        return 2;
    int x = 2;
    while (1) {
        // 計算循環賽的比賽數量
        int roundRobinMatches = x * (x - 1) / 2;
        // 如果循環賽的比賽數量大於n，則沒有解答
        if (roundRobinMatches > n)
            return -1;
        // 如果循環賽的比賽數量等於n，則x是所需的學生數量
        if (roundRobinMatches == n)
            return x;
        // 如果循環賽的比賽數量小於n，則檢查是否可以通過對決賽達到n
        if ((n - roundRobinMatches) % (x / 2) == 0)
            return x;
        // 增加學生數量並重複檢查
        x++;
    }
}
int main() {
    printf("%d\n", findMinimumStudents(25));
    // for (int i = 2; i < 101; i += 4) {
    //     int k = calculateMatches(i);
    //     printf("%d\n", k);
    // }
}
