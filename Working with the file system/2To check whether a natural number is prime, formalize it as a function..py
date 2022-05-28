#проверка простоты числа
def isprime(x):
    d = 2
    while x % d != 0:
        d += 1
    return x == d

#запись в файл числ [100, 200]
filename = '20.dat'
f = open(filename, 'wb+')
for i in range(100, 201):
    if isprime(i):
        bx = i.to_bytes(2, byteorder = 'little', signed = False)
        f.write(bx)

#чтение файла
f.seek(0)
bx = f.read(2)
while bx != b'':
    x = int.from_bytes(bx, byteorder='little', 
                  signed=False)
    print(x)
    bx = f.read(2)

f.close()
