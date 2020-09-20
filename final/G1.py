from PIL import Image, ImageDraw

# Dimensions del triangle
a = int(input())
b = int(input())

n = a + b # Costat del quadrat gran

# Creem una imatge n x n amb fons 'Black'
img = Image.new('RGB', [n, n], 'Black')
dib = ImageDraw.Draw(img)

# Dibuixem els triangles, anant amb compte de no dibuixar píxels de més
dib.polygon([(0, 0), (a - 1, 0), (0, b - 1)], 'Red')
dib.polygon([(n - 1, 0), (a, 0), (n - 1, a - 1)], 'Yellow')
dib.polygon([(n - 1, n - 1), (b, n - 1), (n - 1, a)], 'Green')
dib.polygon([(0, n - 1), (0, b), (b - 1, n - 1)], 'Blue')

# Guardem la imatge
img.save('output.png')
