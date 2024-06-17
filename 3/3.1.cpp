#include <iostream>
#include <cmath>
#include <iomanip>

// Функция для интегрирования
double f(double x) {
    return x * (3 + sqrt(x));
}

// Метод прямоугольников
double rectangleMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// Метод трапеций
double trapezoidMethod(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// Метод Симпсона
double simpsonMethod(double a, double b, int n) {
    if (n % 2 != 0) {
        ++n; // n должно быть четным для метода Симпсона
    }
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2) {
        sum += 4 * f(a + i * h);
    }
    for (int i = 2; i < n; i += 2) {
        sum += 2 * f(a + i * h);
    }
    return sum * h / 3;
}

int main() {
    double a = 1.0;
    double b = 2.0;
    int n = 1000000; // Число разбиений для достижения точности 10^-6

    double resultRectangle = rectangleMethod(a, b, n);
    double resultTrapezoid = trapezoidMethod(a, b, n);
    double resultSimpson = simpsonMethod(a, b, n);

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Метод прямоугольников: " << resultRectangle << std::endl;
    std::cout << "Метод трапеций: " << resultTrapezoid << std::endl;
    std::cout << "Метод Симпсона: " << resultSimpson << std::endl;

    return 0;
}
