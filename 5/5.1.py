import numpy as np
import scipy.interpolate as interp
import matplotlib.pyplot as plt

# Узлы интерполяции
x = np.array([0.0, 1.0, 2.0, 3.0, 4.0])
y = np.array([0.0, 0.5, 0.86603, 0.0, 0.86603])

# Построение кубического сплайна с нулевой кривизной на концах (натуральный сплайн)
spline = interp.CubicSpline(x, y, bc_type='natural')

# Вычисление значения в точке x = 1.5
x_val = 1.5
y_val = spline(x_val)

print(f'Значение функции в точке x = {x_val}: y = {y_val:.5f}')

# График функции и сплайна
x_dense = np.linspace(min(x), max(x), 1000)
y_dense = spline(x_dense)

plt.plot(x, y, 'o', label='Узлы интерполяции')
plt.plot(x_dense, y_dense, label='Кубический сплайн')
plt.plot(x_val, y_val, 'ro', label=f'Точка ({x_val}, {y_val:.5f})')
plt.legend()
plt.xlabel('x')
plt.ylabel('y')
plt.title('Кубический сплайн')
plt.show()