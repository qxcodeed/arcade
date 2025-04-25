def main() -> None:
    # v: Vector = Vector(0)

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
                # v = Vector(int(args[1]))
                pass
            elif cmd == "push":
                # for value in args[1:]:
                    # v.push_back(int(value))
                pass
            elif cmd == "show":
                # print(v)
                pass
            elif cmd == "status":
                # print(v.status())
                pass
            elif cmd == "pop":
                # v.pop_back()
                pass
            elif cmd == "insert":
                # v.insert(int(args[1]), int(args[2]))
                pass
            elif cmd == "erase":
                # v.erase(int(args[1]))
                pass
            elif cmd == "indexOf":
                # print(v.index_of(int(args[1])))
                pass
            elif cmd == "contains":
                # print("true" if v.contains(int(args[1])) else "false")
                pass
            elif cmd == "clear":
                # v.clear()
                pass
            elif cmd == "capacity":
                # print(v.capacity_())
                pass
            elif cmd == "get":
                # print(v.at(int(args[1])))
                pass
            elif cmd == "set":
                # v.set(int(args[1]), int(args[2]))
                pass
            elif cmd == "reserve":
                # v.reserve(int(args[1]))
                pass
            elif cmd == "sort":
                # v.sort()
                pass
            elif cmd == "sorted":
                # print("[" + ", ".join(str(x) for x in v.sorted_()) + "]")
                pass
            elif cmd == "reverse":
                # v.reverse()
                pass
            else:
                print("fail: comando invalido")
        except Exception as e:
            print(e)


if __name__ == "__main__":
    main()
