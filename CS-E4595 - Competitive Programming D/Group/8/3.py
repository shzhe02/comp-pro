def karat(x,y):
    if len(str(x)) == 1 or len(str(y)) == 1:
        return x*y
    else:
        m = max(len(str(x)),len(str(y)))
        k = m // 2

        a = x // 10**k
        b = x % 10**k
        c = y // 10**k
        d = y % 10**k

        z0 = karat(b,d)
        z1 = karat((a+b),(c+d))
        z2 = karat(a,c)

        return (z2 * 10**(2*m2)) + ((z1 - z2 - z0) * 10**(m2)) + (z0)

x = int(input());
y = int(input());

print(karat(x, y));