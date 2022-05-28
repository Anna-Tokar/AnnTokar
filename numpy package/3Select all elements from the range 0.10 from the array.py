import numpy as np 

# создаем массив размера arrsize
# с числами в диапазоне [-20, 20]
arrsize = int(input('Введите размер массива: '))
arr = np.random.randint(-20, 20, size = arrsize)
print('\nМассив из %d эл.:'%arrsize, arr)

# массив с числами [0, 10]
arrfilter = arr[(0 <= arr) & (arr <= 10)]
print('\nМассив чисел в диапазоне [0, 10]:')
print(arrfilter)
