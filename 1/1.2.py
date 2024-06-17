import numpy as np
from scipy.optimize import bisect, newton, fsolve
import math

# Определение функции
def f(x):
    return np.exp(-x) - np.sqrt(x) - 1

# Метод дихотомии (бисекции)
def bisect_method(func, a, b, tol=1e-6):
    return bisect(func, a, b, xtol=tol)

# Метод Ньютона
def newton_method(func, x0, tol=1e-6):
    return newton(func, x0, tol=tol)

# Метод хорд
def secant_method(func, x0, x1, tol=1e-6, max_iter=1000):
    for _ in range(max_iter):
        fx0 = func(x0)
        fx1 = func(x1)
        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0)
        if abs(x2 - x1) < tol:
            return x2
        x0, x1 = x1, x2
    return x1

# Метод итераций (функция для поиска неподвижной точки)
def iteration_method(g, x0, tol=1e-6, max_iter=1000):
    x = x0
    for _ in range(max_iter):
        x_new = g(x)
        if abs(x_new - x) < tol:
            return x_new
        x = x_new
    return x

# Определение начальных условий и точности
a, b = 0.1, 1.0
x0 = 0.5
tol = 1e-6

# Решение уравнения различными методами
root_bisect = bisect_method(f, a, b, tol)
root_newton = newton_method(f, x0, tol)
root_secant = secant_method(f, a, b, tol)
root_iter = iteration_method(lambda x: np.exp(-x) - 1, x0, tol)

print(f'Корень уравнения методом дихотомии: {root_bisect:.6f}')
print(f'Корень уравнения методом Ньютона: {root_newton:.6f}')
print(f'Корень уравнения методом хорд: {root_secant:.6f}')
print(f'Корень уравнения методом итераций: {root_iter:.6f}')
