ctr = 0
for a in range(13):
    for b in range(13):
        for c in range(13):
            if a + b + c + 8 <= 20 and a + b + c > 0:
                ctr += 1

print(ctr)