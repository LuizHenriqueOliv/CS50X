people = {
    "Luiz": "(55)9900-9900",
    "Pedro": "(90)9732-0549",
    "Joao": "(54)9382-9421",
}

name = input("Name: ")

if name in people:
    print(f"Found {people[name]}")
else:
    print("Not found")
