# @DROP
class Vector:
    def __init__(self, capacity: int) -> None:
        self.__data: list[int] = [0] * capacity
        self.__size: int = 0
        self.__capacity: int = capacity

    def push_back(self, value: int) -> None:
        if self.__size == self.__capacity:
            self.reserve(max(1, self.__capacity * 2))
        self.__data[self.__size] = value
        self.__size += 1

    def pop_back(self) -> None:
        if self.__size == 0:
            raise Exception("vector is empty")
        self.__size -= 1

    def insert(self, index: int, value: int) -> None:
        if index < 0 or index > self.__size:
            raise Exception("index out of range")
        if self.__size == self.__capacity:
            self.reserve(max(1, self.__capacity * 2))
        self.__data[index+1:self.__size+1] = self.__data[index:self.__size]
        self.__data[index] = value
        self.__size += 1

    def erase(self, index: int) -> None:
        if index < 0 or index >= self.__size:
            raise Exception("index out of range")
        self.__data[index:self.__size-1] = self.__data[index+1:self.__size]
        self.__size -= 1

    def index_of(self, value: int) -> int:
        for i in range(self.__size):
            if self.__data[i] == value:
                return i
        return -1

    def contains(self, value: int) -> bool:
        return self.index_of(value) != -1

    def reserve(self, new_capacity: int) -> None:
        if new_capacity > self.__capacity:
            new_data: list[int] = [0] * new_capacity
            new_data[:self.__size] = self.__data[:self.__size]
            self.__data = new_data
            self.__capacity = new_capacity

    def size(self) -> int:
        return self.__size

    def capacity(self) -> int:
        return self.__capacity

    def status(self) -> str:
        return f"size:{self.__size} capacity:{self.__capacity}"

    def __str__(self) -> str:
        return "[" + ", ".join(str(self.__data[i]) for i in range(self.__size)) + "]"

    def get(self, index: int) -> int:
        return self.__data[index]

    def at(self, index: int) -> int:
        if index < 0 or index >= self.__size:
            raise Exception("index out of range")
        return self.__data[index]

    def set(self, index: int, value: int) -> None:
        if index < 0 or index >= self.__size:
            raise Exception("index out of range")
        self.__data[index] = value

    def clear(self) -> None:
        self.__size = 0


# @KEEP
def main() -> None:
    v: Vector = Vector(0)  # @COM

    while True:
        print("$", end="")
        line: str = input()
        args: list[str] = line.split()
        print(line)
        cmd: str = args[0]
        try:
            if cmd == "end":
                return
            elif cmd == "init":
                v = Vector(int(args[1]))  # @COM
                # pass # @UNC
            elif cmd == "push":
                for value in args[1:]:    # @COM
                    v.push_back(int(value)) # @COM
                # pass # @UNC
            elif cmd == "show":
                print(v)                   # @COM
                # pass # @UNC
            elif cmd == "status":
                print(v.status())          # @COM
                # pass # @UNC
            elif cmd == "pop":
                v.pop_back()              # @COM
                # pass # @UNC
            elif cmd == "insert":
                v.insert(int(args[1]), int(args[2]))  # @COM
                # pass # @UNC
            elif cmd == "erase":
                v.erase(int(args[1]))    # @COM
                # pass # @UNC
            elif cmd == "indexOf":
                print(v.index_of(int(args[1])))  # @COM
                # pass # @UNC
            elif cmd == "contains":
                print("true" if v.contains(int(args[1])) else "false")  # @COM
                # pass # @UNC
            elif cmd == "clear":
                v.clear()                 # @COM
                # pass # @UNC
            elif cmd == "capacity":
                print(v.capacity())      # @COM
                # pass # @UNC
            elif cmd == "get":
                print(v.at(int(args[1])))  # @COM
                # pass # @UNC
            elif cmd == "set":
                v.set(int(args[1]), int(args[2]))  # @COM
                # pass # @UNC
            elif cmd == "reserve":
                v.reserve(int(args[1]))  # @COM
                # pass # @UNC
            else:
                print("fail: comando invalido")
        except Exception as e:
            print(e)


if __name__ == "__main__":
    main()
