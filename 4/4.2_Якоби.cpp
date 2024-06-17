#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool converge(const vector<double> &prev, const vector<double> &curr, double epsilon) {
    for (int i = 0; i < prev.size(); i++) {
        if (fabs(prev[i] - curr[i]) > epsilon) {
            return false;
        }
    }
    return true;
}

vector<double> jacobiMethod(const vector<vector<double>> &matrix, const vector<double> &b, double epsilon, int maxIterations) {
    int n = matrix.size();
    vector<double> x(n, 0.0), x_new(n);
    int iter = 0;

    while (iter < maxIterations) {
        for (int i = 0; i < n; i++) {
            double sum = b[i];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= matrix[i][j] * x[j];
                }
            }
            x_new[i] = sum / matrix[i][i];
        }

        if (converge(x, x_new, epsilon)) {
            break;
        }

        x = x_new;
        iter++;
    }

    return x;
}

int main() {
    vector<vector<double>> matrix = {
        {7, -3, 3},
        {1, -8, 1},
        {6, -6, 2}
    };

    vector<double> b = {1, 1, -1};

    double epsilon = 1e-6;
    int maxIterations = 1000;

    vector<double> result = jacobiMethod(matrix, b, epsilon, maxIterations);

    cout << "Solution using Jacobi's method:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "x" << i + 1 << " = " << result[i] << endl;
    }

    return 0;
}