from tkinter import *
from math import sqrt

#тест
# 1, -7, 12 - 4 решения
# 1, -5, 4 - 4 решения
# 2, 3, 4 - отрицательный дискриминант
# 1, 14, 48 - x1^2 < 0 и x2^2 < 0
# 1, 3, -4 - 2 решения
# 1, 19, -2 - 2 решения

# функция - решение
def decisive_device(a,b,c):
    # disk - дискриминант
    disk = b*b - 4*a*c
    if disk >= 0:
        p1 = (-b + sqrt(disk)) / (2*a)
        p2 = (-b - sqrt(disk)) / (2*a)
        if (p1 < 0) and (p2 < 0):
            text = "No elements because: \nx1^2 = %s \nx2^2 = %s \n" %(p1, p2)
        elif (p1 < 0):
            x1 = sqrt(p2)
            x2 = -sqrt(p2)
            text = "X1 = %s \nX2 = %s \n" % (x1, x2)
        elif (p2 < 0):
            x1 = sqrt(p1)
            x2 = -sqrt(p1)
            text = "X1 = %s \nX2 = %s \n" % (x1, x2)
        else:
            x1 = sqrt(p1)
            x2 = -sqrt(p1)
            x3 = sqrt(p2)
            x4 = -sqrt(p2)
            text = "X1 = %s \nX2 = %s \nX3 = %s \nX4 = %s \n" % (x1, x2, x3, x4)
    else:
        text = "The discriminant is: %s \n This equation has no solutions" % disk
    return text

def handler():
    try:
        a_val = float(a.get())
        b_val = float(b.get())
        c_val = float(c.get())
        # вставка через функцию insertion решения через функцию decisive_device
        output.insert("0.0", decisive_device(a_val, b_val, c_val))
    except ValueError:
        # если ввели меньше 3 аргументов или не цифры.
        output.insert("0.0", "Make sure you entered 3 numbers")

# основная программа

root = Tk()
# устанавливаем название окна
root.title("The biquadrate equation. Calculator")
# устанавливаем размер окна
root.minsize(600,500)
# выключаем возможность изменять окно
root.resizable(width=False, height=False)

# создаем рабочую область - Виджет Frame (рамка) предназначен для организации виджетов внутри окна
# Свойство bd отвечает за толщину края рамки.
frame = Frame(root, bg = 'red',bd = 7, relief = FLAT)
# grid - этот упаковщик представляет собой таблицу с ячейками, в которые помещаются виджеты.
frame.grid()

# поле для ввода первого аргумента уравнения (a)
# width - задаёт длину элемента в знакоместах.
a = Entry(frame, width = 5)
# row - номер строки, в который помещаем виджет.
# column - номер столбца, в который помещаем виджет.
a.grid(row = 1,column = 1)

# текст после первого аргумента
# Label - это виджет для отображения к-л надписи без возможности редактирования пользователем.
a_lab = Label(frame, text="x^4 + ").grid(row = 1,column = 2)

# поле для ввода второго аргумента уравнения (b)
b = Entry(frame, width = 5)
b.grid(row = 1,column = 3)
b_lab = Label(frame, text="x^2 + ").grid(row = 1, column = 4)

# поле для ввода третьего аргумента уравнения (с)
c = Entry(frame, width = 5)
c.grid(row = 1, column = 5)
c_lab = Label(frame, text=" = 0").grid(row = 1, column = 6)

# кнопка решить
but = Button(frame, text = "Solve", command = handler).grid(row = 1, column = 7)

# место для вывода решения уравнения
output = Text(frame, bg="pink", font="Courier 20", width=35, height=10)
output.grid(row = 2, columnspan = 8)

# запускаем главное окно
root.mainloop()