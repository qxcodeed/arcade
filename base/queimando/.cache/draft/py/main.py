# -*- coding: utf-8 -*-

class Pos:
    def __init__(self, l: int, c: int):
        self.l: int = l
        self.c: int = c

    # Sobrescreve o método __eq__ para permitir comparação direta de objetos Pos
    def __eq__(self, other: object) -> bool:
        if not isinstance(other, Pos):
            return NotImplemented
        return self.l == other.l and self.c == other.c
    
# Retorna uma lista de vizinhos (acima, abaixo, esquerda, direita)
def get_neib(p: Pos) -> list[Pos]: # Usando 'list' diretamente
    return [
        Pos(p.l - 1, p.c),
        Pos(p.l + 1, p.c),
        Pos(p.l, p.c - 1),
        Pos(p.l, p.c + 1),
    ]

# Verifica se a posição está dentro da matriz
def inside(mat: list[list[str]], p: Pos) -> bool: # Usando 'list' diretamente
    """
    Essa função retorna uma booleana que
    diz se a posição p está dentro da
    matriz mat
    """
    return 0 <= p.l < len(mat) and 0 <= p.c < len(mat[0])

# Função para propagar a "chama" (substitui '#' por 'o')
def queimar(mat: list[list[str]], l: int, c: int) -> None: # Usando 'list' diretamente
    """
    Essa função deve usar uma list como pilha
    e marcar as árvores na matriz como
    queimados.
    Uma sugestão de como fazer isso é:
    - adicionar a primeira posição na pilha se possível tocar fogo nele
    - enquanto a pilha não estiver vazia:
      - pegar o elemento do topo
      - ver se tem algum de seus vizinhos que pode ser queimado
      - se sim, tocar fogo nele e adicionar na pilha
      - se não, remover o elemento do topo da pilha
    """
    pass
# Função para exibir a matriz
def show_mat(mat: list[list[str]]) -> None: # Usando 'list' diretamente
    for row in mat:
        print("".join(row)) # Junta os caracteres de volta em uma string para imprimir

def main() -> None:
    nl, nc, l, c = map(int, input().split()) # Alterado para input()
    _ = nc

    mat: list[list[str]] = [] # Usando 'list' diretamente
    for _ in range(nl):
        mat.append(list(input().strip())) # Alterado para input()

    queimar(mat, l, c) # Chama a função de queimar
    show_mat(mat) # Exibe o resultado

# Garante que main() seja chamado apenas quando o script for executado diretamente
if __name__ == "__main__":
    main()
