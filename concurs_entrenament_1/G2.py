from PIL import Image, ImageDraw

# Llegim les variables
c1 = input()
c2 = input()
n = int(input())

# Llegim la llista de nombre i n'agafem el màxim
v = [int(input()) for i in range(n)]
m = max(v)

# Creem la imatge
img = Image.new('RGB', (50*(n + 2), 50*(m + 2)), c1)
dib = ImageDraw.Draw(img)

# Funció per dibuixar un rectangle,
# donada la seva distància x al costat esquerre de la imatge i l'alçada màxima
def dibuixa_rectangle(x, h):
    dib.polygon([(x, h), (x + 49, h), (x + 49, 50*m + 49), (x, 50*m + 49)], c2)

# Dibuixem tots els rectangles
for i, x in enumerate(v):
    dibuixa_rectangle(50*(i + 1), 50*(m + 1 - x)) 

# Guardem la imatge
img.save('output.png')
