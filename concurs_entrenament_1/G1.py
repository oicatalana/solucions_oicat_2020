from PIL import Image, ImageDraw

# Llegim les variables
c1 = input()
c2 = input()
n = int(input())
m = int(input())

# Creem la imatge
img = Image.new('RGB', (n, m), c1)
dib = ImageDraw.Draw(img)

# Dibuixem el triangle superior
dib.polygon([(0, 0), (n//2, n//2), (n - 1, 0)], c2)

# Guardem la imatge
img.save('output.png')
