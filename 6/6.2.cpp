#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

// Определение функции
double f2(const std::vector<double>& x) {
    return x[0] + 2 * x[1] + 4 * std::sqrt(1 + x[0] * x[0] + x[1] * x[1]);
}

// Градиент функции
std::vector<double> grad_f2(const std::vector<double>& x) {
    double denom = std::sqrt(1 + x[0] * x[0] + x[1] * x[1]);
    double df_dx1 = 1 + 4 * x[0] / denom;
    double df_dx2 = 2 + 4 * x[1] / denom;
    return {df_dx1, df_dx2};
}

// Линейный поиск для выбора шага
double line_search(const std::vector<double>& x, const std::vector<double>& d, double alpha = 1, double beta = 0.5, double sigma = 1e-4) {
    std::vector<double> x_new(2);
    while (true) {
        x_new[0] = x[0] - alpha * d[0];
        x_new[1] = x[1] - alpha * d[1];
        if (f2(x_new) <= f2(x) - sigma * alpha * (d[0] * d[0] + d[1] * d[1])) {
            break;
        }
        alpha *= beta;
    }
    return alpha;
}

// Метод наискорейшего спуска
std::vector<double> steepest_descent(const std::vector<double>& x0, double tolerance = 1e-6, int max_iterations = 1000) {
    std::vector<double> x = x0;
    for (int i = 0; i < max_iterations; ++i) {
        std::vector<double> grad = grad_f2(x);
        double grad_norm = std::sqrt(grad[0] * grad[0] + grad[1] * grad[1]);
        if (grad_norm < tolerance) {
            break;
        }
        double alpha = line_search(x, grad);
        x[0] -= alpha * grad[0];
        x[1] -= alpha * grad[1];
    }
    return x;
}

int main() {
    std::vector<double> x0 = {1.0, 1.0};
    std::vector<double> result = steepest_descent(x0);

    std::cout << "Оптимум функции f2: (" << result[0] << ", " << result[1] << ")" << std::endl;
    std::cout << "Значение функции: " << f2(result) << std::endl;

    return 0;
}