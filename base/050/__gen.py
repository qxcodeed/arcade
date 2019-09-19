import random

alfabeto = "abcdefghijklmnopqrstuvwxyz"
a = ""
for x in range(10):
	qtde = random.randint(1,10)
	qtdc = random.randint(1,10)
	print(">>>>>>>> 0%d" % x)
	print (qtde)
	for x in range(qtde):
		aux = random.randint(1,5)
		for y in range(aux):
			a += random.choice(alfabeto)
		print (a)
		a=""
	print(qtdc)
	a=""
	for x in range(qtdc):
		aux = random.randint(1,5)
		for y in range(aux):
			a += random.choice(alfabeto)
		print (a)
		a=""
	print("========")
	print()
	print("<<<<<<<<")
	print()

 		
