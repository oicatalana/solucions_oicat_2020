# Solució: 10!/(4! * 4! * 2!)

def factorial(n):
    return 1 if n == 0 else n*factorial(n - 1)

print(factorial(10)//(factorial(4)*factorial(4)*factorial(2)))