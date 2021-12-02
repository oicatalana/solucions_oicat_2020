from PIL import Image, ImageDraw

# Llegim les variables
n = int(input())

# Creem la imatge
img = Image.new('RGB', (8*n, 8*n), 'White')
dib = ImageDraw.Draw(img)

# Dibuixem el triangle superior
dib.ellipse([0*n, 0*n, 8*n - 1, 8*n - 1], 'Blue')
dib.ellipse([1*n, 1*n, 7*n - 1, 7*n - 1], 'Yellow')
dib.ellipse([2*n, 2*n, 6*n - 1, 6*n - 1], 'Red')
dib.ellipse([3*n, 3*n, 5*n - 1, 5*n - 1], 'Green')

# Guardem la imatge
img.save('output.png')
