N = int(raw_input().strip())
count = max = 0

i = 1
while i < N:
    if (N & i) == i:
        count = count + 1
    else:
        if count > max:
            max = count
        count = 0
    i = i*2

if count > max: max = count
print max
