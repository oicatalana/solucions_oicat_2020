from PIL import Image, ImageDraw

# Diccionari per a convertir cada caràcter a "Braille"
lletra_a_braille = {
    'A': "X.....",
    'B': "X.X...",
    'C': "XX....",
    'D': "XX.X..",
    'E': "X..X..",
    'F': "XXX...",
    'G': "XXXX..",
    'H': "X.XX..",
    'I': ".XX...",
    'J': ".XXX..",
    '1': "X.....",
    '2': "X.X...",
    '3': "XX....",
    '4': "XX.X..",
    '5': "X..X..",
    '6': "XXX...",
    '7': "XXXX..",
    '8': "X.XX..",
    '9': ".XX...",
    '0': ".XXX..",
    '#': ".X.XXX",
    ' ': "......"
}

s = input()

braille = []
llegint_nombre = False
for c in s:
    if c == ' ':
        llegint_nombre = False
    if (c.isdecimal()):
        if not llegint_nombre:
            llegint_nombre = True
            braille.append(lletra_a_braille['#']) # Si comencem a llegir un nombre, posem una '#' 
    
    braille.append(lletra_a_braille[c])

n = len(braille)

# Creem la imatge, amb les dimensions adequades
img = Image.new('RGB', [90*n - 30, 90], 'LightBlue')
dib = ImageDraw.Draw(img)

def dibuixa_cercle(x, y, col):
    dib.ellipse([x + 3, y + 3, x + 26, y + 26], col)

# Dibuixem
for p in range(n):
    for j in range(3):
        for i in range(2):
            col = 'Black' if braille[p][2*j + i] == 'X' else 'White'
            dibuixa_cercle(90*p + 30*i, 30*j, col)

# Guardem
img.save('output.png')
