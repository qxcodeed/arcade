import random

for i in range(10):
    print(">>>>>>>>")
    qtd = random.randint(0, 40)
    print(qtd)
    for j in range(qtd):
        print(random.randint(10, 99), end = ' ')
    print("")
    print("========")
    print("<<<<<<<<\n\n")