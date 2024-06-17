#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

int main() {
    // Определение комплексных чисел
    complex<double> z1(-1, 1);
    complex<double> z2(-3, 2);
    complex<double> z3(-1, 2);

    // Сумма
    complex<double> sum = z1 + z2;
    cout << "Сумма: " << sum << endl;

    // Разность
    complex<double> diff = z1 - z2;
    cout << "Разность: " << diff << endl;

    // Произведение
    complex<double> prod = z1 * z2;
    cout << "Произведение: " << prod << endl;

    // Частное
    complex<double> quot = z1 / z2;
    cout << "Частное: " << quot << endl;

    // Четвертая степень z3
    complex<double> z3_pow4 = pow(z3, 4);
    cout << "z3 в четвертой степени: " << z3_pow4 << endl;

    // Корень третьей степени z3
    complex<double> z3_root3 = pow(z3, 1.0/3);
    cout << "Корень третьей степени из z3: " << z3_root3 << endl;

    return 0;
}