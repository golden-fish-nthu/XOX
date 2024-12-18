#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 102;
const int MAX_N = 102;
#define adjust(x) (((x) % 10007 + 10007) % 10007)
class Matrix {
   public:
    Matrix() {
        row = col = 0;
        memset(mat, 0, sizeof(mat));
    }
    // TODO
    Matrix(int r, int c);
    const int& getrow() {
        return row;
    }
    const int& getcol() {
        return col;
    }
    // TODO
    int* operator[](const int& x);
    const int* operator[](const int& x) const {
        return mat[x];
    }
    // TODO
    Matrix operator+(const Matrix& x) const;
    // TODO: note that this function is declared with the keyword "friend"
    friend Matrix operator*(const Matrix& x, const Matrix& y);
    void print() {
        for (int i = 0; i < row; i++) {
            if (i == 0)
                std::cout << "/";
            else if (i == row - 1)
                std::cout << "\\";
            else
                std::cout << "|";
            for (int j = 0; j < col; j++) {
                std::cout << std::right << std::setw(8) << mat[i][j];
            }
            if (i == 0)
                std::cout << " \\\n";
            else if (i == row - 1)
                std::cout << " /\n";
            else
                std::cout << " |\n";
        }
    }

   private:
    int mat[MAX_N][MAX_N];
    int row, col;
};
Matrix::Matrix(int r, int c) {
    this->row = r;
    this->col = c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            mat[i][j] = 0;
}

int* Matrix::operator[](const int& x) {
    return mat[x];
}

Matrix Matrix::operator+(const Matrix& x) const {
    Matrix result(row, col);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            result[i][j] = adjust(mat[i][j] + x[i][j]);
    return result;
}

Matrix operator*(const Matrix& x, const Matrix& y) {
    Matrix result(x.row, y.col);
    for (int i = 0; i < x.row; i++)
        for (int j = 0; j < y.col; j++)
            for (int k = 0; k < x.col; k++)
                result[i][j] = adjust(result[i][j] + x[i][k] * y[k][j]);
    return result;
}