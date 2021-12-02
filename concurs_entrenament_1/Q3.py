# Retorna true si el nombre es autodescriptiu
def és_autodescriptiu(n):
    rep = [0]*10        # rep[i]: Nombre de cops que apareix el caràcter i
    num = [None]*10     # num[i]: i-èssim caràcter de n

    # Anem construint rep i num
    for i in range(9, -1, -1):
        rep[n % 10] += 1
        num[i] = n % 10
        n //= 10

    # Retorna true si rep i num són iguals. A python es pot fer així:
    return rep == num

# Els nombres autodescriptius tenen 10 xifres
# (incloent possibles 0's a l'esquerra),
# i els seus digits sumen 10.
# Aquesta funció troba tots els nombres n
# de p = 10 xifres amb suma de dígits s = 10
def backtracking(n, p, s):
    # Si portem p = 10 xifres, mirem si el nombre és autodescriptiu
    if p == 10:
        if s == 10 and és_autodescriptiu(n):
            print(n)
        return
    
    # Afegim el dígit d al final, sempre que els dígits no sumin més de 10
    for d in range(10):
        if s + d <= 10:
            backtracking(10*n + d, p + 1, s + d)

# Iniciem el backtracking
backtracking(0, 0, 0)
