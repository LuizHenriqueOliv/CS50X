from cs50 import get_float

while True:
    change = get_float("Change: ")
    if change > 0:
        break

n_25c = change / 0.25
change -= n_25c * 0.25

n_10c = change / 0.10
change -= n_10c * 0.10

n_5c = change / 0.05
change -= n_5c * 0.05

n_1c = change / 0.01

total = n_25c + n_10c + n_5c + n_1c

print(f"{total}")
