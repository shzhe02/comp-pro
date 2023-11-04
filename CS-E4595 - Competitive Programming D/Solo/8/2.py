mess = input()
len = len(mess)

def fact(n):
    out = 1
    for i in range(1, n + 1):
        out *= i
    return out

perms = fact(len)

count = {}
for chr in mess:
    count[chr] = count.get(chr, 0) + 1;

div = 1;

for k, v in count.items():
     div *= fact(v)

print(perms // div)