#include <iostream>
#include <cmath>
using namespace std;

struct Vector {
    double x, y;
};

double length(const Vector& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

double dotProduct(const Vector& v1, const Vector& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

double angleBetween(const Vector& v1, const Vector& v2) {
    double dot = dotProduct(v1, v2);
    double len1 = length(v1);
    double len2 = length(v2);
    return acos(dot / (len1 * len2)) * 180.0 / M_PI; // углы в градусах
}

Vector add(const Vector& v1, const Vector& v2) {
    return { v1.x + v2.x, v1.y + v2.y };
}

Vector subtract(const Vector& v1, const Vector& v2) {
    return { v1.x - v2.x, v1.y - v2.y };
}

bool areParallel(const Vector& v1, const Vector& v2) {
    return (v1.x * v2.y == v1.y * v2.x);
}

int main() {
    Vector A, B, C;

    // Ввод координат векторов
    cout << "Введите координаты вектора A (x y): ";
    cin >> A.x >> A.y;
    cout << "Введите координаты вектора B (x y): ";
    cin >> B.x >> B.y;
    cout << "Введите координаты вектора C (x y): ";
    cin >> C.x >> C.y;

    // Длины векторов
    cout << "Длина вектора A: " << length(A) << endl;
    cout << "Длина вектора B: " << length(B) << endl;
    cout << "Длина вектора C: " << length(C) << endl;

    // Углы между векторами
    cout << "Угол между векторами A и B: " << angleBetween(A, B) << " градусов" << endl;
    cout << "Угол между векторами A и C: " << angleBetween(A, C) << " градусов" << endl;
    cout << "Угол между векторами B и C: " << angleBetween(B, C) << " градусов" << endl;

    // Суммы и разности векторов
    Vector sumAB = add(A, B);
    Vector diffAB = subtract(A, B);
    cout << "Сумма векторов A и B: (" << sumAB.x << ", " << sumAB.y << ")" << endl;
    cout << "Разность векторов A и B: (" << diffAB.x << ", " << diffAB.y << ")" << endl;

    Vector sumAC = add(A, C);
    Vector diffAC = subtract(A, C);
    cout << "Сумма векторов A и C: (" << sumAC.x << ", " << sumAC.y << ")" << endl;
    cout << "Разность векторов A и C: (" << diffAC.x << ", " << diffAC.y << ")" << endl;

    Vector sumBC = add(B, C);
    Vector diffBC = subtract(B, C);
    cout << "Сумма векторов B и C: (" << sumBC.x << ", " << sumBC.y << ")" << endl;
    cout << "Разность векторов B и C: (" << diffBC.x << ", " << diffBC.y << ")" << endl;

    // Проверка параллельности
    cout << "Векторы A и B " << (areParallel(A, B) ? "параллельны" : "не параллельны") << endl;
    cout << "Векторы A и C " << (areParallel(A, C) ? "параллельны" : "не параллельны") << endl;
    cout << "Векторы B и C " << (areParallel(B, C) ? "параллельны" : "не параллельны") << endl;

    return 0;
}