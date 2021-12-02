from PIL import Image, ImageDraw

# Llegim les variables
n = int(input())

# Creem la imatge
img = Image.new('RGB', [100*n, 100])
dib = ImageDraw.Draw(img)

# Llegim la llista dels n colors i immediatament després la ordenem
colors = sorted([input() for _ in range(n)])

# Dibuixem els quadrats
for i in range(n):
    dib.polygon([
        (100*i, 0),
        (100*i + 99, 0),
        (100*i + 99, 99),
        (100*i, 99)
    ], colors[i])

# Guardem la imatge
img.save('output.png')
