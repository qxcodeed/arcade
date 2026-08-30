class Node:
    def __init__(self, value: int):
        self.value = value
        self.left: Node | None = None
        self.right: Node | None = None

def my_show(node: Node | None, depth: int):
    # @UNC
    # TODO
    # return
    # @DROP
    if node is None:
        print("." * 4 * depth + "#")
        return
    if node.left is not None or node.right is not None:
        my_show(node.left, depth + 1)
    print("." * 4 * depth + str(node.value))
    if node.left is not None or node.right is not None:
        my_show(node.right, depth + 1)

#--------------------------------------------    
# Não altere o resto do código
    
def bshow(node: Node | None, history: str = ""):
    if node is not None and (node.left is not None or node.right is not None):
        bshow(node.left, history + "l")
    for i in range(len(history) - 1):
        print("│   " if history[i] != history[i+1] else "    ", end="")
    if history:
        print("╭───" if history[-1] == 'l' else "╰───", end="")    
    if node is None:
        print("#")
        return
    print(node.value)
    if node.left is not None or node.right is not None:
        bshow(node.right, history + "r")
    
def create(parts: list[str]) -> Node | None:
    elem = parts[0]
    del parts[0]
    if elem == "#":
        return None

    value = int(elem)
    node = Node(value)
    node.left = create(parts)
    node.right = create(parts)
    return node

if __name__ == "__main__":
    line = input().strip()
    root = create(line.split())
    bshow(root)
    my_show(root, 0)
