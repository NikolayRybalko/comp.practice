def series_sum(x, epsilon=1e-6):
    sum_result = 0.0
    k = 1
    term = 1.0  # начальное значение для выполнения цикла

    while abs(term) > epsilon:
        term = ((-1) ** (k - 1)) / (2.3 ** k + k * x)
        sum_result += term
        k += 1

    return sum_result

# Пример использования
x = 1.0  # Можно заменить на любое значение x
epsilon = 1e-6
result = series_sum(x, epsilon)
print(f"Сумма ряда для x = {x} с точностью до {epsilon}: {result:.10f}")