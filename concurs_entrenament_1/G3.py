from PIL import Image, ImageDraw

# Llegim les variables
c1 = input()
c2 = input()
n = int(input())
m = int(input())

# Creem la imatge
img = Image.new('RGB', (50*n, 50*m), c1)
dib = ImageDraw.Draw(img)

# Funció per calcular el màxim comú divisor amb l'algorisme d'Euclides
def gcd (a, b):
    return a if b == 0 else gcd(b, a%b)

k = 2*gcd(n - 1, m - 1)

# La posició (i, j) serà part de la tajectòria si i només si
# i + j o i - j són un múltiple de k
for i in range(n):
    for j in range(m):
        if ((i + j) % k == 0 or (i - j) % k == 0):
            dib.ellipse([50*i, 50*j, 50*i + 49, 50*j + 49], c2)

# Guardem la imatge
img.save('output.png')
