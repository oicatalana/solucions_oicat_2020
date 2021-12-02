# Solució 1:
solucio = 0

for n in range(20, 61):
    residu = n % 10
    if residu > 0 and n % residu == 0:
        solucio += 1

print(solucio)

# Solució 2:
print(len([n for n in range(20, 61) if n % 10 > 0 and n % (n % 10) == 0]))
