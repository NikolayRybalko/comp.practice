#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    double x, y, z;
};

struct Vector {
    double x, y, z;
};

struct Plane {
    double A, B, C, D;
};

Vector crossProduct(const Vector& v1, const Vector& v2) {
    return { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
}

double dotProduct(const Vector& v1, const Vector& v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

double magnitude(const Vector& v) {
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vector direction(const Point& p1, const Point& p2) {
    return { p2.x - p1.x, p2.y - p1.y, p2.z - p1.z };
}

double distancePointToPlane(const Point& p, const Plane& pl) {
    return fabs(pl.A * p.x + pl.B * p.y + pl.C * p.z + pl.D) / sqrt(pl.A * pl.B * pl.C);
}

bool isParallel(const Vector& d, const Plane& pl) {
    return dotProduct(d, { pl.A, pl.B, pl.C }) == 0;
}

Point intersectionPoint(const Point& p0, const Vector& d, const Plane& pl) {
    double t = -(pl.A * p0.x + pl.B * p0.y + pl.C * p0.z + pl.D) / (pl.A * d.x + pl.B * d.y + pl.C * d.z);
    return { p0.x + t * d.x, p0.y + t * d.y, p0.z + t * d.z };
}

double angleBetween(const Vector& d, const Plane& pl) {
    return asin(dotProduct(d, { pl.A, pl.B, pl.C }) / (magnitude(d) * magnitude({ pl.A, pl.B, pl.C }))) * 180.0 / M_PI;
}

int main() {
    Point P0;
    Vector d;
    Plane pl;

    // Ввод данных
    cout << "Введите координаты точки на прямой (x0 y0 z0): ";
    cin >> P0.x >> P0.y >> P0.z;
    cout << "Введите направляющие вектора прямой (a b c): ";
    cin >> d.x >> d.y >> d.z;
    cout << "Введите коэффициенты плоскости (A B C D): ";
    cin >> pl.A >> pl.B >> pl.C >> pl.D;

    // Угол между прямой и плоскостью
    double angle = angleBetween(d, pl);
    cout << "Угол между прямой и плоскостью: " << angle << " градусов" << endl;

    // Проверка параллельности
    if (isParallel(d, pl)) {
        cout << "Прямая и плоскость параллельны." << endl;
        double dist = distancePointToPlane(P0, pl);
        cout << "Расстояние между прямой и плоскостью: " << dist << endl;
    } else {
        cout << "Прямая и плоскость пересекаются." << endl;
        Point intersection = intersectionPoint(P0, d, pl);
        cout << "Координаты точки пересечения: (" << intersection.x << ", " << intersection.y << ", " << intersection.z << ")" << endl;
    }

    return 0;
}