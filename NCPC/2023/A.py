import sys
sys.

n, k = map(int, input().split())
arr = [0]
mul = 0
while len(arr) < n and mul < k:
    arr = arr * k
    mul += 1
    arr.append(1)
if len(arr) < n:
    for i in range(len(arr), n):
        arr.append(1)
count = 0
for i in range(n):
    if arr[i] == 1:
        count += 1
print(count)
