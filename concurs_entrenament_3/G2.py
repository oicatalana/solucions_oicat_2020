from PIL import Image, ImageDraw

# Llegim l'entrada
n = int(input())

# Creem la imatge, amb la mida corresponent
img = Image.new('RGB', (50*n, 50))
dib = ImageDraw.Draw(img)

# Anem llegint els n colors i pintant el quadrats
# donant les posicions dels seus vèrtexs.
# Vigileu amb no pintar píxels de més!
for i in range(n):
    color = input()
    dib.polygon([
        (50*i, 0),
        (50*i, 49),
        (50*i + 49, 49),
        (50*i + 49, 0)
    ], color)

# Guardem la imatge
img.save('output.png')
