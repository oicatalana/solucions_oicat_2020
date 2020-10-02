from PIL import Image, ImageDraw

nom_color = ['Blue', 'Green', 'Pink', 'Red', 'Yellow']

# Llegim l'entrada
n = int(input())

def factorial(n):
    if n == 0:
        return 1
    return n*factorial(n - 1)

# Creem la imatge
img = Image.new('RGB', [20*factorial(n), 20*n], 'White')
dib = ImageDraw.Draw(img)

columna = 0     # Columna on estem dibuixant els cercles
fila = [-1]*n   # fila[c] = fila on és el color c, o -1 si encara no hi és a cap

def backtracking(fila_actual):
    global columna

    # Si ja els hem posat tots, dibuixem
    if fila_actual == n:
        for color in range(n):
            dib.ellipse([20*columna, 20*fila[color], 20*columna + 19, 20*fila[color] + 19], nom_color[color])
        columna += 1
        return
    
    # Si no, afegim cada opció i continuem recursivament
    for color in range(n):
        if fila[color] == -1:               # Si no s'ha posat...
            fila[color] = fila_actual       # Afegim el color no usat
            backtracking(fila_actual + 1)   # Continuem recursivament
            fila[color] = -1                # Desfem el canvi

# Comencem el backtracking
backtracking(0)

# Guardem la imatge
img.save('output.png')
