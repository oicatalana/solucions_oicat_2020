from PIL import Image, ImageDraw

# Llegim l'entrada
n = int(input())
l = int(input())

# Llegim les temperatures inicials
T_inicial = []
for i in range(l):
    T_inicial.append(int(input()))

# Formem la primera fila de la "matriu de temperatures"
M = [T_inicial]

# Creem la imatge
img = Image.new('RGB', [10*l, 10*n], 'Black')
dib = ImageDraw.Draw(img)

# Actualizem, usant maxs i mins ens estalviem problemes amb els extrems
for t in range(1, n):
    M.append([0]*l)
    for i in range(l):
        M[t][i] = (M[t - 1][max(0, i - 1)] + M[t - 1][i] + M[t - 1][min(l - 1, i + 1)])//3

# Funció Rainbow
def Rainbow(z):
    if z < 255:
        return (255, z, 0)
    if z < 510:
        return (510 - z, 255, 0) 
    if z < 765:
        return (0, 255, z - 510)
    if z < 1020:
        return (0, 1020 - z, 255)
    if z < 1275:
        return (z - 1020, 0, 255)
    if z < 1530:
        return (255, 0, 1530 - z)

# Dibuixem cada quadradet
for j in range(n):
    for i in range(l):
        dib.polygon([(10*i, 10*j), (10*i + 9, 10*j), (10*i + 9, 10*j + 9), (10*i, 10*j + 9)], Rainbow(1200 - M[j][i]))

# Guardem la imatge
img.save('output.png')
