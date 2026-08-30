def better_search(arr: list[int], value: int) -> tuple[bool, int]:
    """
    Retorna a posição do elemento x na lista arr ou onde ele deve ser inserido.
    """
    # @UNC
    # return False, 0
    # @DROP
    low, high = 0, len(arr)
    while low < high:
        mid = (low + high) // 2
        if arr[mid] == value:
            return True, mid
        elif arr[mid] < value:
            low = mid + 1
        else:
            high = mid
    return False, low

# @KEEP
args = input().split()[1:-1]
vet: list[int] = []
for i in range(len(args)):
    vet.append(int(args[i]))

value = int(input())
result = better_search(vet, value)
print("V" if result[0] else "F", result[1])
