import numpy as np

n = int(input('Введите количество строк: '))
m = int(input('Введите количество столбцов: '))
a = np.random.randint(10, size = (n, m))
print(a)

s = np.sum(a)
print("Сумма всех элементов матрицы = ", s)
sr = np.mean(a)
print("Среднее значение всех элементов = ", sr)
m = np.min(a)
print("Минимальное значение в матрице = ", m)
