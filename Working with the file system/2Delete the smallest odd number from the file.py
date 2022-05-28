import random

#создание двоичного файла
filename = '26.dat'
f = open(filename, 'wb+')
n = random.randint(10, 20)
print('Список случайных', n, 'чисел: ')

#заполнения файла случайными числами в количестве n в диапозоне (-100, 100)
for i in range(n):
    bnum = random.randint(-100, 100)
    bx = bnum.to_bytes(2, byteorder = 'little', signed = True)
    f.write(bx)

#чтение файла
f.seek(0)
bx = f.read(2)
i = 0
while bx != b'':
    i += 1
    x = int.from_bytes(bx, byteorder='little', signed=True)
    print(x)
    bx = f.read(2)

#поиск нечетного минимума
f.seek(0)
bx = f.read(2)
xmin = 22
imin = 0
while bx != b'':
    x = int.from_bytes(bx, byteorder='little', signed=True)
    if (x % 2 == 1 and x < xmin):
        xmin = x
        imin = f.tell() - 2
    bx = f.read(2)
print()
print('Минимальное нечетное число: ', xmin, end='\n\n')

#удаление минимума из файла с помощью truncate
if (xmin != 22):
    f.seek(-2, 2)
    bnum = f.read(2)
    x = int.from_bytes(bnum, byteorder='little',
                  signed=True)
    f.seek(-2, 2)
    f.truncate()
    f.seek(imin)
    bx = x.to_bytes(2, byteorder = 'little', signed = True)
    f.write(bx)

#печать содержимого файла
print('Измененный файл: ')
f.seek(0)
bx = f.read(2)
while bx != b'':
    i += 1
    x = int.from_bytes(bx, byteorder='little', signed=True)
    print(x)
    bx = f.read(2)

f.close()
