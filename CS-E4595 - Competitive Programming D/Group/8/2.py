n = int(input())

values = []

for i in range(n):
    vals = input().split(' ')
    values.append([int(vals[0]), int(vals[1]), int(vals[2]), int(vals[3])])

absoluteMin = values[n - 1][1];
if (n == 1):
    print(max(absoluteMin, values[0][3]))
for i in reversed(range(n)):
    

print(values)