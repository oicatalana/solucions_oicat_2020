primers = [2, 3, 5, 7]

def primer(n):
    i = 2
    while i*i <= n:
        if n%i == 0:
            return False
        i += 1
    return True

for i in range(2, 21):
    # Amb '1'*i creem un string amb i 1's
    # i amb int() transformem a enter
    x = int('1'*i)
    if primer(x): 
        primers.append(x)

print(*primers, sep='-')