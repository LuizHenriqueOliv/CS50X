from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

change *= 100

n_25c = change / 25
change -= n_25c * 25

n_10c = change / 10
change -= n_10c * 10

n_5c = change / 5
change -= n_5c * 5

n_1c = change / 1

total = n_25c + n_10c + n_5c + n_1c

print(f"{total}")
