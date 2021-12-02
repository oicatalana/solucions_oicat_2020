from PIL import Image, ImageDraw
from math import sin

# Llegim les variables
m = int(input())
n = int(input())
d = int(input())
rx = int(input())
ry = int(input())
gx = int(input())
gy = int(input())
bx = int(input())
by = int(input())

# Creem la imatge
img = Image.new('RGB', (m, n))
dib = ImageDraw.Draw(img)

# Dibuixem cada punt amb el color corresponent
for x in range(m):
    for y in range(n):
        R = int(rx*sin(x/d) + ry*sin(y/d)) % 256
        G = int(gx*sin(x/d) + gy*sin(y/d)) % 256
        B = int(bx*sin(x/d) + by*sin(y/d)) % 256
        dib.point((x, y), (R, G, B))

# Guardem la imatge
img.save('output.png')
