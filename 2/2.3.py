
import math

# Параметры эллипса
h = float(input("Введите координату x центра эллипса (h): "))
k = float(input("Введите координату y центра эллипса (k): "))
a = float(input("Введите длину большой полуоси эллипса (a): "))
b = float(input("Введите длину малой полуоси эллипса (b): "))

# Координаты точки
x0 = float(input("Введите координату x точки: "))
y0 = float(input("Введите координату y точки: "))

# Проверка принадлежности точки эллипсу
def is_point_on_ellipse(h, k, a, b, x0, y0):
    return ((x0 - h) ** 2) / a ** 2 + ((y0 - k) ** 2) / b ** 2 == 1

if is_point_on_ellipse(h, k, a, b, x0, y0):
    print("Точка принадлежит эллипсу.")
else:
    print("Точка не принадлежит эллипсу.")

# Нахождение координат фокусов
c = math.sqrt(a ** 2 - b ** 2)
focus1 = (h + c, k)
focus2 = (h - c, k)

print(f"Координаты фокусов эллипса: {focus1} и {focus2}")

# Нахождение эксцентриситета
e = c / a
print(f"Эксцентриситет эллипса: {e}")

# Нахождение расстояния от директрис до центра
d = a / e
print(f"Расстояние от директрис до центра эллипса: {d}")