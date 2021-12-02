from PIL import Image, ImageDraw

# Llegim l'entrada
c1 = input()
c2 = input()
k = int(input())
n = int(input())
m = int(input())
patro = [input() for _ in range(m)]

# Creem la imatge
img = Image.new('RGB', (n**k, m**k), c2)
dib = ImageDraw.Draw(img)

# Funció que dibuixa el fractal corresponent al rectangle de mida
# (n^p, m^p) amb vèrtex superior esquerre a (x, y)
def fractal(x, y, p):
    # Si p és 0, hem de pintar el punt (x, y) i no continuar
    if p == 0:
        dib.point((x, y), c1)
        return
    for j in range(m):
        for i in range(n):
            # Si tenim una 'X' al patró, cal seguir dibuixant el
            # subrectangle corresponent:
            if patro[j][i] == 'X':
                fractal(x + i*(n**(p - 1)), y + j*(m**(p - 1)), p - 1)

# Dibuixem el fractal
fractal(0, 0, k)

# Guardem la imatge
img.save('output.png')
