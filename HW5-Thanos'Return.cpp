#define adjust(x) (((x) % 10007 + 10007) % 10007)

Matrix::Matrix(int r, int c) {
    this->row = r;
    this->col = c;
    memset(mat, 0, sizeof(mat));
}

int *Matrix::operator[](const int &x) {
    return mat[x];
}

Matrix Matrix::operator+(const Matrix &x) const {
    Matrix result(row, col);
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            result[i][j] = adjust(mat[i][j] + x[i][j]);
        }
    }
    return result;
}

Matrix operator*(const Matrix &x, const Matrix &y) {
    Matrix result(x.row, y.col);
    for (size_t i = 0; i < x.row; i++) {
        for (size_t j = 0; j < y.col; j++) {
            for (size_t k = 0; k < x.col; k++) {
                result[i][j] = adjust(result[i][j] + x[i][k] * y[k][j]);
            }
        }
    }
    return result;
}
