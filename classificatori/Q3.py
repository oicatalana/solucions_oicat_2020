def prime(n):
    i = 2
    while i*i <= n:
        if n%i == 0:
            return False
        i += 1
    return n >= 2

ans = -1

def backtracking(n):
    global ans              # Marquem ans com a variable global
    if not prime(n):        # Si el nombre que ens queda no és primer, no continuem
        return                    
    ans = max(ans, n)       # Si ho és, actualitzem la solució
    for i in range(10):     # I intentem posar un dígit més a la dreta, sabent que els prefixos trobats són primers
        backtracking(10*n + i)

for i in [2, 3, 5, 7]:      # El primer nombre només pot ser un nombre primer...
    backtracking(i)

print(ans)
