class Node:
    def __init__(self, value: int):
        self.value = value
        self.left: Node | None = None
        self.right: Node | None = None

# Consuma uma lista de strings para construir uma árvore binária.
# Você pode obter o elemento 0 da lista em cada chamada recursiva
# e remover esse elemento da lista usando del parts[0].
def create(parts: list[str]) -> Node | None:
    return None
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
    
if __name__ == "__main__":
    line = input().strip()
    root = create(line.split())
    bshow(root)
