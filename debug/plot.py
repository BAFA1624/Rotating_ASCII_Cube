import numpy as np
import matplotlib.pyplot as plt

x = []
y = []

with open("data.csv", "r") as file:
    for line in file.readlines()[1:]:
        xstr, ystr = line.split(",")
        print(xstr, ystr)
        x.append(float(xstr.strip()))
        y.append(float(ystr.strip()))

plt.plot(x, y)
plt.show()
