from PIL import Image, ImageDraw

color_false = input()
color_true = input()
k = int(input())
n = int(input())
m = int(input())

patro = []
for i in range(m):
	patro.append(input())

img = Image.new('RGB', [n**k, m**k], 'Black')
dib = ImageDraw.Draw(img)

# A fractal(x, y, k, b) li passem els següents arguments:
# x, y: el píxel superior esquerre del subrectangle on estem
# r: el subrectangle on estem té dimensions [n^r, m^r]
# b: un booleà que serà True si cal invertir el color
def fractal (x, y, r, b):
	if r == 0:
		col = color_true if b else color_false
		dib.point([x, y], col)
		return
	for j in range (m):
		for i in range (n):
			if patro[j][i] == 'F':
				fractal(x + i*(n**(r - 1)), y + j*(m**(r - 1)), r - 1, b)
			if patro[j][i] == 'T':
				fractal(x + i*(n**(r - 1)), y + j*(m**(r - 1)), r - 1, not b)

fractal(0, 0, k, False)
	
img.save('output.png')
