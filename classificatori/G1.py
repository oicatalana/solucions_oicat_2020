from PIL import Image, ImageDraw

# Llegim
n = int(input())
m = int(input())
c = input()
f = input()

# Creem la imatge
img = Image.new('RGB', (25*n, 25*m), f)
dib = ImageDraw.Draw(img)

def draw_line(x1, y1, x2, y2):
    dib.line([(25*x1 + 12, 25*y1 + 12), (25*x2 + 12, 25*y2 + 12)], c)

for j in range(m):
    # Dibuixem el·lipses i línies horitzontals
    for i in range(n):
        dib.ellipse([25*i + 5, 25*j + 5, 25*i + 19, 25*j + 19], c)
        if i > 0:
            draw_line(i - 1, j, i, j)

    # Dibuixem la línia vertical
    if j > 0:
        x = 0 if j%2 == 0 else n - 1
        draw_line(x, j - 1, x, j)

# Guardem la imatge
img.save('output.png')
