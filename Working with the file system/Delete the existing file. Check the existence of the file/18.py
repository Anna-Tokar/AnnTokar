import os # подключить модуль os
os.remove('18 задание_1.txt')

if os.path.exists('18 задание_1.txt'):
    print("Файл существует")
else:
    print("Файл не существует")

if os.path.exists('18 задание_2.txt'):
    print("Файл существует")
else:
    print("Файл не существует")