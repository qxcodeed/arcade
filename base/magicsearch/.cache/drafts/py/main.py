
def magic_search(lst, value):
    return -1

def main() -> None:
    parts = input().strip().split() 
    slice_ = list(map(int, parts[1:-1])) 

    value = int(input().strip()) 

    result = magic_search(slice_, value) 
    print(result)


if __name__ == "__main__":
    main()
