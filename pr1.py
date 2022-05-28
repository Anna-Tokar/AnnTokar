from tkinter import * # подключаем tkinter
from tkinter import messagebox
from tkinter import ttk
import math
import sys

root = Tk( ) # создаем главное окно
root.title("Calculate.") # заголовок окна

# Можно задать минимальные и максимальные размеры
root.minsize(600,300)

# Создаем список с именами будущих кнопок калькулятора.
bttn_list = [
"0", "1", "2", "+", "*",
"3", "4", "5", "-", "/",
"6", "7", "8", "=", "%",
"9", ".",  "C", "(", ")",
"Exit" ]

# создаем кнопки для нашего калькулятора.
r = 1
c = 0
# проходим по список с именами кнопок калькулятора.
for i in bttn_list:
    rel = ""
    cmd = lambda x = i: calc(x)
    # Для создания кнопки используется конструктор Button()
    # Grid – это менеджер геометрии, который размещает виджеты в двухмерной сетке - столбцы и строки
    # width = 10 - ширина
    ttk.Button(root, text = i, command = cmd, width = 10).grid(row = r, column = c)
    c += 1 # следующий столбец
    if c > 4:  # переход на новую строку
        c = 0
        r += 1

# поле ввода называется Entry
calc_entry = Entry(root, width = 33)
# columnspan - сколько столбцов занимает виджет.
calc_entry.grid(row = 0, column = 0, columnspan = 5)

#логика калькулятора
def calc(key):
    global memory
    if key == "=":
        #исключение написания слов
        # разрешаем вводить только символы -+0123456789.*/)(, а запрещаем вводить.
        str1 = "0123456789.-+*%/)("
        # get - извлекает текст
        if calc_entry.get()[0] not in str1:
            # insert - добавляет текст (END - всё)
            calc_entry.insert(END, "First symbol is not number!")
            messagebox.showerror("Error!", "You did not enter the number!")
        # вычисления
        try:
            # eval - будет считать в нашей программе.
            result = eval(calc_entry.get())
            calc_entry.insert(END, "=" + str(result))
        except:
            # выведет ошибку, например, при делении на 0
            calc_entry.insert(END, " - Error!")
            messagebox.showerror("Error!", "Check the correctness of data")

    # очищение поля ввода
    elif key == "C":
        calc_entry.delete(0, END)

    elif key == "Exit":
        root.after(1,root.destroy)
        sys.exit

    elif key == "(":
        calc_entry.insert(END, "(")

    elif key == ")":
        calc_entry.insert(END, ")")

    else:
        if "=" in calc_entry.get():
            calc_entry.delete(0, END)
        calc_entry.insert(END, key)


root.mainloop()