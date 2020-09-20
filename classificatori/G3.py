from PIL import Image, ImageDraw

# Llegim 
n = int(input())
m = int(input())
mapa = []
for i in range(m):
    mapa.append(input())

# Creem la imatge
img = Image.new('RGB', [30*n, 30*m])
dib = ImageDraw.Draw(img)

# Marquem totes les caselles com a no visitades
visitat = []
for i in range(m):
    visitat.append([False]*n)

# Guardem la posició inicial d'en Den
den = [-1, -1]
for i in range(m):
    for j in range(n):
        if mapa[i][j] == 'D':
            den = [j, i]

# Direccions possibles
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

# Retorna true si la casella està dins del mapa
def ok(x, y):
    return x >= 0 and y >= 0 and x < n and y < m

def dfs(x, y):
    visitat[y][x] = True    # Marquem la casella com a visitada
    # Per a cada posició (X, Y) adjacent, visitem-la si podem
    for i in range(4):      
        X, Y = x + dx[i], y + dy[i]
        if ok(X, Y) and not visitat[Y][X] and mapa[Y][X] != 'A' and not (mapa[y][x] == 'B' and mapa[Y][X] == 'C'):
            dfs(x + dx[i], y + dy[i])

dfs(den[0], den[1]) # Comencem a explorar des de la posició del Den

# Dibuixem
for i in range(m):
    for j in range(n):
        col = 'Aqua'
        if mapa[i][j] == 'B':
            col = 'LawnGreen' if visitat[i][j] else 'ForestGreen'
        if mapa[i][j] == 'C':
            col = 'Silver' if visitat[i][j] else 'Black'
        if mapa[i][j] == 'D':
            col = 'Yellow'
        dib.rectangle([30*j, 30*i, 30*j + 29, 30*i + 29], col)

# Guardem
img.save('output.png')
