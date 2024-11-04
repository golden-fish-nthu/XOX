#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const float EPSILON = 1e-7f;  // 誤差範圍
const int MAX_YEARS = 1000;   // 最大迭代年數限制
typedef vector<vector<float>> Matrix;
typedef vector<float> Vector;

// 矩陣乘法
Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, Vector(n, 0.0f));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}

// 矩陣快速冪
Matrix matrixPower(const Matrix& A, int power) {
    int n = A.size();
    Matrix result(n, Vector(n, 0.0f));
    Matrix base = A;
    // 初始化單位矩陣
    for (int i = 0; i < n; ++i)
        result[i][i] = 1.0f;
    while (power > 0) {
        if (power % 2 == 1)
            result = multiply(result, base);
        base = multiply(base, base);
        power /= 2;
    }
    return result;
}

// 向量與矩陣乘法
Vector multiplyVector(const Matrix& A, const Vector& X) {
    int n = A.size();
    Vector result(n, 0.0f);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i] += A[i][j] * X[j];
    return result;
}

// 比較兩個向量是否相等
bool isEqual(const Vector& X1, const Vector& X2) {
    int n = X1.size();
    for (int i = 0; i < n; ++i)
        if (fabs(X1[i] - X2[i]) > EPSILON)
            return false;
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        // 讀取馬可夫矩陣 A
        Matrix A(n, Vector(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];
        // 讀取初始狀態向量 X0
        Vector X0(n);
        for (int i = 0; i < n; ++i)
            cin >> X0[i];
        // 讀取目標人口 p
        float p;
        cin >> p;

        if (X0[0] <= p) {
            cout << "0" << endl;
            continue;
        }

        int left = 0, right = MAX_YEARS;
        int answer = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            Matrix A_power = matrixPower(A, mid);
            Vector Xn = multiplyVector(A_power, X0);
            if (Xn[0] <= p)
                answer = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        cout << ((answer != -1 && answer <= MAX_YEARS) ? to_string(answer) : "Never") << endl;
    }
    return 0;
}