from cs50 import get_string

# coletar a sequência do cartão
card_number = get_string("Informe a sequência do cartão: ")

# verificar pelo algoritmo de Luhn
for i in range(len(card_number)):
    print(card_number[i])

# verificar a bandeira do cartão
