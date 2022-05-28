from tkinter import *
from math import *
from tkinter.messagebox import *

root = Tk()
root.title("Program that computeslogical expressions.")

win1 = Frame(root)
win1.pack(anchor = "n", expand = YES, fill = X)
lx = Label(win1, text = "x=")
lx.pack(side = LEFT, padx = 10, pady = 10)

entX = Entry(win1)
entX.insert(0, 0)
entX.pack(side = LEFT, padx = 10, pady = 10)
entX.focus()

ly = Label(win1, text = "y= ")
ly.pack(side = LEFT, padx = 10, pady = 10)

entY = Entry(win1)
entY.insert(0, 0)
entY.pack(side = LEFT, padx = 10, pady = 10)

win2 = Frame(root)
win2.pack(anchor = "n", expand = YES, fill = X)
Label(win2, text = "F: ").pack(side = LEFT, padx = 10, pady = 10)

entF = Entry(win2)
entF.pack(side = LEFT, padx = 10, pady = 10, expand = YES, fill = X)
entF.insert(0,"not (x1 and y1) or (x2 and y2) = 1")

def res():
    try:
        x = [int(elem) for elem in entX.get().split()]
    except ValueError:
        showerror("Filling error, Variable x is not an integer")
        return
    try:
        y = [int(elem) for elem in entY.get().split()]
    except ValueError:
        showerror("Filling error, Variable y is not an integer")
        return
    F = entF.get()
    for i in range(len(x)):
        F = F.replace('x' + str(i + 1),'x' + str([i]))
    for i in range(len(y)):
        F = F.replace('y' + str(i + 1),'y' + str([i]))
    F = F.replace('=','==')
    if eval(F):
        labF['text'] = "True"
    else:
        labF['text'] = "False"


Button(win2, text = 'Calculate', command = res).pack(side = LEFT, padx = 10, pady = 5)
labF = Label(win2, text = " ")
labF.pack(side = LEFT, padx = 10, pady = 10)
root.mainloop()