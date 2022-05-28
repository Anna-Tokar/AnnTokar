import numpy as np
from numpy import linalg as LA

# создаем квадратную матрицу размером matrsize
# с числами [-10, 10]
matrsize = int(input('Введите размерность матрицы: '))
print('\nМатрица (%dx%d):'%(matrsize, matrsize))
matrix = np.random.randint(-10, 10, size = (matrsize, matrsize))
print(matrix)

# находим собственные значения и вектора матрицы
vals, vecs = LA.eig(matrix)
print('Собственные значения матрицы:\n', vals, end='\n')
print('Собственные вектора матрицы:\n', vecs)
