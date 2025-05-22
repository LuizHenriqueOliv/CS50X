import cs50

while True:
    height = cs50.get_int("Height: ")
    if height > 0:
        break
for i in range(height):
    print("#")
