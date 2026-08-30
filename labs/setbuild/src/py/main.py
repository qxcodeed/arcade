# @DROP
class Set:
    def __init__(self, capacity: int) -> None:
        self.__data: list[int] = [0] * capacity
        self.__size: int = 0
        self.__capacity: int = capacity

    def __binary_search(self, value: int) -> int:
        low, high = 0, self.__size - 1
        while low <= high:
            mid = (low + high) // 2
            if self.__data[mid] == value:
                return mid
            elif self.__data[mid] < value:
                low = mid + 1
            else:
                high = mid - 1
        return -1

    def insert(self, value: int) -> None:
        if self.__size == self.__capacity:
            self.reserve(max(1, self.__capacity * 2))
        if self.__binary_search(value) != -1:
            return  # já contém, não insere
        self.__data[self.__size] = value
        self.__size += 1
        # manter ordenado (simula ordenação)
        self.__data[:self.__size] = sorted(self.__data[:self.__size])

    def erase(self, value: int) -> bool:
        index = self.__binary_search(value)
        if index == -1:
            return False
        # remover deslocando para esquerda
        for i in range(index, self.__size - 1):
            self.__data[i] = self.__data[i + 1]
        self.__size -= 1
        return True

    def contains(self, value: int) -> bool:
        return self.__binary_search(value) != -1

    def reserve(self, new_capacity: int) -> None:
        if new_capacity > self.__capacity:
            new_data = [0] * new_capacity
            new_data[:self.__size] = self.__data[:self.__size]
            self.__data = new_data
            self.__capacity = new_capacity

    def clear(self) -> None:
        self.__size = 0

    def size(self) -> int:
        return self.__size

    def capacity(self) -> int:
        return self.__capacity

    def status(self) -> str:
        return f"size:{self.__size} capacity:{self.__capacity}"

    def __str__(self) -> str:
        if self.__size == 0:
            return "[]"
        return "[" + ", ".join(str(self.__data[i]) for i in range(self.__size)) + "]"


# @KEEP
def main() -> None:
    s: Set = Set(0)  # @COM

    while True:
        print("$", end="")
        line = input()
        print(line)
        args = line.split()
        if not args:
            continue

        cmd = args[0]

        try:
            if cmd == "end":
                return
            elif cmd == "init":
                s = Set(int(args[1]))     # @COM
                # pass # @UNC
            elif cmd == "insert":
                for value in args[1:]:    # @COM
                    s.insert(int(value))  # @COM
                # pass # @UNC
            elif cmd == "show":
                print(s)  # @COM
                # pass # @UNC
            elif cmd == "erase":
                if not s.erase(int(args[1])):  # @COM
                    print("value not found")   # @COM
                # pass # @UNC
            elif cmd == "contains":
                print("true" if s.contains(int(args[1])) else "false")  # @COM
                # pass # @UNC
            elif cmd == "clear":
                s.clear()  # @COM
                # pass # @UNC
            else:
                print("fail: comando invalido")
        except Exception as e:
            print(e)


if __name__ == "__main__":
    main()
