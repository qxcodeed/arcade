import random
vet = []
for x in range(10):
	print(">>>>>>>>")
	n = random.randint(2,10)
	print(n)
	for x in range(n):
		vet.append(random.randint(1,1000))
	for x in range(n):
		print(vet[x-1], end = " ")
	print()
	m = random.randint(1,n-1)
	print(m)
	for x in range(m):
		print(vet[random.randint(0,n-1)], end = " ")
	print()
	print("========")
	print("<<<<<<<<")
	print()
	vet = []