sample = input()

idx = 0

while idx != len(sample) - 1:
    if sample[idx].isdigit():
        digit = int(sample[idx])
        copy = sample[idx + 1:idx + 1 + digit]
        sample = sample.replace(sample[idx], copy, 1)
    else:
        idx += 1

print(sample)
