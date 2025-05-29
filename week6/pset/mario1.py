from cs50 import get_int

height = get_int("Height: ")

while True:
    if (height >= 0 and height <= 8):
        break

for i in range(height):
    print(" ", * (height - 1), end="")
    print("#", * (i + 1), end="")
    print()
