import sympy
from sympy import *
from sympy.plotting import plot
from sympy.abc import*

print("--------------------1.1----------------------------------")
print(limit((sin(x)) / x, x, 0))
print('\n')


print("--------------------2.2----------------------------------")
pprint(summation((1 / n**2), (n, 1, oo)))
print('\n')
print(summation(1 / n**2, (n, 1, oo)))
print('\n')


print("--------------------3.4----------------------------------")
# The diff() function inside the SymPy library can be used to calculate the derivative of a function.
x = Symbol('x')
# Define function
f = x**x
# Calculating Derivative
derivative_f3 = f.diff(x)
print("= ",derivative_f3)
print('\n')


print("--------------------4.1----------------------------------")
#init_printing(use_unicode=False, wrap_line=False, no_global=True)
p = Symbol('p')
integrate_f4 = integrate(x**p, x).evalf()

print("= ", integrate_f4)
print('\n')


print("--------------------5.4----------------------------------")
x = symbols('x', real=True)
Calculate_f5_1 = solve((x**7+7*x**5+3*x**4+5*x**3+26*x**2-10*x+40),x)
print('\n')
print(Calculate_f5_1)

print('\n')
#a = simplify('x**7+7*x**5+3*x**4+5*x**3+26*x**2-10*x+40')
#print(a.subs(x, -12).evalf())

from sympy.simplify.simplify import nthroot
print('= ', nroots(x**7+7*x**5+3*x**4+5*x**3+26*x**2-10*x+40, 3))


print("--------------------6.3----------------------------------")
print('\n')
plot(x**7+7*x**5+3*x**4+5*x**3+26*x**2-10*x+40, xlim =[-2, 2], ylim=[-10,100], line_color='red')