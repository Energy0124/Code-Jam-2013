import math


piii = math.pi
temp = raw_input()
temp = temp.split(" ")

N = int(temp[0])
R = float(temp[1])

temp = raw_input()
temp = temp.split(" ")
x0 = float(temp[0])
y0 = float(temp[1])

initialX = x0
initialY = y0

result = 0.0
for i in range(1, N, 1):
    temp = raw_input()
    temp = temp.split(" ")
    x1 = float(temp[0])
    y1 = float(temp[1])

    result += math.sqrt((x0 - x1) ** 2 + (y0 - y1) ** 2)
    x0 = x1
    y0 = y1

result += math.sqrt(((initialX - x0) ** 2 + (initialY - y0) ** 2))
result += 2 * (piii) * R

print "%0.2f" % result


