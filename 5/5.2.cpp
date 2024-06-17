#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для вычисления разделенных разностей
vector<double> dividedDifferences(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    vector<vector<double>> coef(n, vector<double>(n));
    
    for (int i = 0; i < n; i++) {
        coef[i][0] = y[i];
    }
    
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            coef[i][j] = (coef[i + 1][j - 1] - coef[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
    
    vector<double> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = coef[0][i];
    }
    return result;
}

// Функция для вычисления интерполяционного многочлена Ньютона
double newtonInterpolation(const vector<double>& x, const vector<double>& coef, double x_val) {
    int n = x.size();
    double result = coef[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        result = result * (x_val - x[i]) + coef[i];
    }
    return result;
}

int main() {
    vector<double> x = {0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI};
    vector<double> y;
    
    for (double xi : x) {
        y.push_back(cos(xi));
    }
    
    vector<double> coef = dividedDifferences(x, y);
    
    double x_star = 0.25 * M_PI;
    double y_interp = newtonInterpolation(x, coef, x_star);
    double y_actual = cos(x_star);
    double error = fabs(y_actual - y_interp);
    
    cout << "Значение интерполяции в точке x* = " << x_star << ": y = " << y_interp << endl;
    cout << "Фактическое значение в точке x* = " << x_star << ": y = " << y_actual << endl;
    cout << "Погрешность интерполяции: Δ(y(x*)) = " << error << endl;
    
    return 0;
}