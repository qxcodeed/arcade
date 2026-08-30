
def magic_search(lst, value):
    # return -1 # @UNC
    # @DROP
    low, high = 0, len(lst) - 1 
    pos = -1
    while low <= high:
        mid = (low + high) // 2
        if lst[mid] == value:
            pos = mid
            break
        elif lst[mid] < value:
            low = mid + 1
        else:
            high = mid - 1
    if pos != -1:
        while pos + 1 < len(lst) and lst[pos + 1] == value:
            pos += 1
        return pos
    return low

# @KEEP

def main() -> None:
    parts = input().strip().split() 
    slice_ = list(map(int, parts[1:-1])) 

    value = int(input().strip()) 

    result = magic_search(slice_, value) 
    print(result)


if __name__ == "__main__":
    main()
