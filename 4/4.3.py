import numpy as np

def seidel_method(matrix, b, epsilon=0.01, max_iterations=1000):
    n = len(b)
    x = np.zeros(n)

    for _ in range(max_iterations):
        x_new = np.copy(x)
        for i in range(n):
            s = sum(matrix[i][j] * x_new[j] for j in range(n) if i != j)
            x_new[i] = (b[i] - s) / matrix[i][i]

        if np.allclose(x, x_new, atol=epsilon):
            break

        x = x_new

    return x

matrix = np.array([
    [28, 9, -3, -7],
    [-5, 21, -5, -3],
    [-8, 1, -16, 5],
    [0, -2, 5, 8]
])

b = np.array([-159, 63, -45, 24])

result = seidel_method(matrix, b)
print("Solution using Seidel's method:")
for i, x in enumerate(result):
    print(f"x{i+1} = {x}")
