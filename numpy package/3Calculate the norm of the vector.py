from numpy import *


n = int(input('>>>'))
a = list()
for i in range(0, n):
    y = random.randint(-100, 100)
    a.append(y)

print(a)
norm = linalg.norm(a)
print(norm)
