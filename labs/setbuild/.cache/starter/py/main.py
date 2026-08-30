def main() -> None:
    # s: Set = Set(0)

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
                # s = Set(int(args[1]))
                pass
            elif cmd == "insert":
                # for value in args[1:]:
                    # s.insert(int(value))
                pass
            elif cmd == "show":
                # print(s)
                pass
            elif cmd == "erase":
                # if not s.erase(int(args[1])):
                    # print("value not found")
                pass
            elif cmd == "contains":
                # print("true" if s.contains(int(args[1])) else "false")
                pass
            elif cmd == "clear":
                # s.clear()
                pass
            else:
                print("fail: comando invalido")
        except Exception as e:
            print(e)


if __name__ == "__main__":
    main()
