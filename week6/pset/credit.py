from cs50 import get_string

# coletar a sequência do cartão
card_number = get_string("Informe a sequência do cartão: ")
soma = 0

# verificar pelo algoritmo de Luhn
for i in range(len(card_number) - 2, -1, -2):
    digit = int(card_number[i]) * 2
    if digit > 9:
        digit1 = digit // 10
        digit2 = digit % 10
        soma += digit1 + digit2
    else:
        soma += digit

for i in range(len(card_number) - 1, -1, -2):
    soma += int(card_number[i])

# verificar a bandeira do cartão
if soma % 10 == 0:
    if len(card_number) == 15 and card_number.startswith(("34", "37")):
        print("AMEX")
    elif len(card_number) == 16 and card_number.startswith(("51", "52", "53", "54", "55")):
        print("MASTERCARD")
    elif len(card_number) in [13, 16] and card_number.startswith("4"):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
