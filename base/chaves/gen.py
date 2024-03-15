import random

for x in range(10):
	print(">>>>>>>>")
	for x in range(15):
		a = random.randint(1,5)
		b = random.randint(1,5)
		while(a == b):
			a = random.randint(1,5)
			b = random.randint(1,5)
		print(a, b)
	print("========")
	print("<<<<<<<<")
	print()
