import numpy as np

def tridiagonal_solver(a, b, c, d):
    n = len(d)
    c_prime = np.zeros(n-1)
    d_prime = np.zeros(n)
    
    c_prime[0] = c[0] / b[0]
    d_prime[0] = d[0] / b[0]
    
    for i in range(1, n-1):
        c_prime[i] = c[i] / (b[i] - a[i] * c_prime[i-1])
    for i in range(1, n):
        d_prime[i] = (d[i] - a[i] * d_prime[i-1]) / (b[i] - a[i] * c_prime[i-1])
    
    x = np.zeros(n)
    x[-1] = d_prime[-1]
    for i in range(n-2, -1, -1):
        x[i] = d_prime[i] - c_prime[i] * x[i+1]
    
    return x

# Уравнения, которые нужно решить:
# -7x -6y = -75
# 6x +12y = 126
# -3y + 5z = 13
# -9z + 21t + 8q = -40
# -5t - 6q = -24

# Первая часть системы: уравнения для x и y
a1 = [0, 6]
b1 = [-7, 12]
c1 = [-6, 0]
d1 = [-75, 126]
xy = tridiagonal_solver(a1, b1, c1, d1)
x, y = xy[0], xy[1]

# Вторая часть системы: уравнение для z
# Это уравнение может быть решено напрямую, так как оно является одноуровневым для z
z = (13 + 3 * y) / 5

# Третья часть системы: уравнения для t и q
a3 = [0, 21]
b3 = [-9, -5]
c3 = [8, 0]
d3 = [-40, -24]
tq = tridiagonal_solver(a3, b3, c3, d3)
t, q = tq[0], tq[1]

print(f"x = {x:.2f}")
print(f"y = {y:.2f}")
print(f"z = {z:.2f}")
print(f"t = {t:.2f}")
print(f"q = {q:.2f}")
