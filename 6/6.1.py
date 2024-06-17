import numpy as np

# Определение функции
def f1(x):
    return x[0] + 5 * x[1] + np.exp(x[0]**2 + x[1]**2)

# Производная функции по x1
def df1_dx1(x):
    return 1 + 2 * x[0] * np.exp(x[0]**2 + x[1]**2)

# Производная функции по x2
def df1_dx2(x):
    return 5 + 2 * x[1] * np.exp(x[0]**2 + x[1]**2)

# Метод покоординатного спуска
def coordinate_descent(f, df1, df2, x0, alpha=0.01, tolerance=1e-6, max_iterations=1000):
    x = np.array(x0)
    for i in range(max_iterations):
        x_prev = np.copy(x)
        # Спуск по первой координате
        x[0] -= alpha * df1(x)
        # Спуск по второй координате
        x[1] -= alpha * df2(x)
        if np.linalg.norm(x - x_prev) < tolerance:
            break
    return x

# Начальное приближение
x0 = [1.0, 1.0]
result = coordinate_descent(f1, df1_dx1, df1_dx2, x0)
print(f'Оптимум функции f1: {result}, значение функции: {f1(result)}')