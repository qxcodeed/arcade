def better_search(arr: list[int], value: int) -> tuple[bool, int]:
    """
    Retorna a posição do elemento x na lista arr ou onde ele deve ser inserido.
    """
    return False, 0
args = input().split()[1:-1]
vet: list[int] = []
for i in range(len(args)):
    vet.append(int(args[i]))

value = int(input())
result = better_search(vet, value)
print("V" if result[0] else "F", result[1])
