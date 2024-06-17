#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void printMatrix(const vector<vector<double>> &matrix, const vector<double> &b) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << matrix[i][j] << " ";
        }
        cout << " | " << setw(10) << b[i] << endl;
    }
    cout << endl;
}

void gaussElimination(vector<vector<double>> &matrix, vector<double> &b) {
    int n = matrix.size();
    
    for (int i = 0; i < n; i++) {
        // Поиск максимального элемента в столбце
        double maxEl = abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(matrix[k][i]) > maxEl) {
                maxEl = abs(matrix[k][i]);
                maxRow = k;
            }
        }

        // Перестановка строк
        for (int k = i; k < n; k++) {
            swap(matrix[maxRow][k], matrix[i][k]);
        }
        swap(b[maxRow], b[i]);

        // Прямой ход
        for (int k = i + 1; k < n; k++) {
            double c = -matrix[k][i] / matrix[i][i];
            for (int j = i; j < n; j++) {
                if (i == j) {
                    matrix[k][j] = 0;
                } else {
                    matrix[k][j] += c * matrix[i][j];
                }
            }
            b[k] += c * b[i];
        }
    }

    // Обратный ход
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i] / matrix[i][i];
        for (int k = i - 1; k >= 0; k--) {
            b[k] -= matrix[k][i] * x[i];
        }
    }

    // Вывод решения
    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main() {
    vector<vector<double>> matrix = {
        {-7, 3, -4, 7},
        {8, -1, -7, 6},
        {9, 9, 3, -6},
        {-7, -9, -8, -5}
    };

    vector<double> b = {-126, 29, 27, 34};

    cout << "Initial Matrix:" << endl;
    printMatrix(matrix, b);

    gaussElimination(matrix, b);

    return 0;
}
