a,b = [int(x) for x in input().split()]

curr_prev = 0
curr = 1

months = 0

while curr <= b:
    if curr >= a:
        months += 1
    tmp = curr_prev
    curr_prev = curr
    curr += tmp

print(months)
