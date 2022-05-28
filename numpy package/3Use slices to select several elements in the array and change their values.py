import numpy as np


x = np.arange(0, 10, 1)
print(x)
x[1:3] = x[4:6]
x[7:9] = x[3:1:-1]
print(x)
