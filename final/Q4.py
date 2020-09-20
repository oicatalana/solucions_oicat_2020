# Podem definir f recursivament
def f(n):
    if n < 10:
        return n**2
    return (n%10)**2 + f(n//10)

raonables = []

for i in range(1, 1000):    # Si i > 999, i segur que no és raonable
    n = i
    for rep in range(1000): # No té més sentit fer més de 1000 iteracions
        n = f(n)
        if n == i:
            raonables.append(i)
            break

print(*raonables, sep = '-')