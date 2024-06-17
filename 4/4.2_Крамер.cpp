#include <iostream>
#include <vector>

using namespace std;

double determinant(const vector<vector<double>> &matrix) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

vector<vector<double>> replaceColumn(const vector<vector<double>> &matrix, const vector<double> &b, int col) {
    vector<vector<double>> newMatrix = matrix;
    for (int i = 0; i < matrix.size(); i++) {
        newMatrix[i][col] = b[i];
    }
    return newMatrix;
}

vector<double> cramerMethod(const vector<vector<double>> &matrix, const vector<double> &b) {
    double det = determinant(matrix);
    vector<double> result;
    for (int i = 0; i < matrix.size(); i++) {
        vector<vector<double>> tempMatrix = replaceColumn(matrix, b, i);
        result.push_back(determinant(tempMatrix) / det);
    }
    return result;
}

int main() {
    vector<vector<double>> matrix = {
        {7, -3, 3},
        {1, -8, 1},
        {6, -6, 2}
    };

    vector<double> b = {1, 1, -1};

    vector<double> result = cramerMethod(matrix, b);

    cout << "Solution using Cramer's method:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "x" << i + 1 << " = " << result[i] << endl;
    }

    return 0;
}
