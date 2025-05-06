from typing import List, Tuple
from random import sample
import argparse
one_solution_board = [
            [7,8,0,4,0,0,1,2,0],
            [6,0,0,0,7,5,0,0,9],
            [0,0,0,6,0,1,0,7,8],
            [0,0,7,0,4,0,2,6,0],
            [0,0,1,0,5,0,9,3,0],
            [9,0,4,0,6,0,0,0,5],
            [0,7,0,3,0,0,0,1,2],
            [1,2,0,0,0,7,4,0,0],
            [0,4,9,2,0,6,0,0,7]
        ]


# board com 2 soluções
two_solution_board = [
            [0,0,0,4,0,0,1,2,0],
            [0,0,0,0,7,5,0,0,9],
            [0,0,0,6,0,1,0,7,8],
            [0,0,7,0,4,0,2,6,0],
            [0,0,1,0,5,0,9,3,0],
            [9,0,4,0,6,0,0,0,5],
            [0,7,0,3,0,0,0,1,2],
            [1,2,0,0,0,7,4,0,0],
            [0,4,9,2,0,6,0,0,7]
        ]

class Board:
    def __init__(self, board):
        self.board = board
        self.places = self.find_empty_places()
        self.solutions = 0

    def print_board(self):
        for l in range(9):
            if(l % 3 == 0 and l != 0):
                print(23 * "-")
            for c in range(9):
                if(c % 3 == 0 and c != 0):
                    print(" |", end="")
                print("", self.board[l][c], end="")
            print("")
        
    def get_lin(self, index) -> List[int]:
        return self.board[index]
    
    def get_col(self, index) -> List[int]:
        return [self.board[l][index] for l in range(9)]

    def get_box(self, lin, col) -> List[int]:
        l = (lin // 3) * 3# divisão inteira
        c = (col // 3) * 3
        return self.board[l][c:c + 3] + self.board[l + 1][c:c+3] + self.board[l + 2][c:c+3]

    def allowed(self, l, c, value) -> bool:
        return (not value in self.get_lin(l)) and (not value in self.get_col(c)) and (not value in self.get_box(l, c))

    # retorna uma tupla com todas as posições com 0
    def find_empty_places(self) -> List[Tuple[int, int]]:
        return  sum([[(l, c) for c in range(9) if self.board[l][c] == 0] for l in range(9)], [])

    def print_stack(self, end = "\n"):
        print(" ".join(map(str, [self.board[l][c] for l, c in self.places if self.board[l][c] != 0])), end = end) 
    
    def solve(self, index = 0):
        if index == len(self.places): # se preenchi todas as posições então deu certo
            return True
        l, c = self.places[index]     # pego as coordenadas dessa posição
        for i in range(1,10):         # de 1 ate 9
            if(self.allowed(l, c, i)):  # se posso colocar esse numero nessa posicao
                self.board[l][c] = i    # coloco o número
                if self.solve(index + 1):  # invoco a recursão pro proximo
                    return True            # se retornou true, então terminamos, para na primeira solução encontrada
        self.board[l][c] = 0               # se nenhum valor deu certo, coloco 0 e retorno false
        return False

    def debug(self, index = 0):
        if index == len(self.places): 
            self.solutions += 1          #incrementa número de soluções encontradas
            self.print_stack(" <---\n")  #mostrando a solução que resolve
            return True
        l, c = self.places[index]     
        for i in range(1,10):         
            if(self.allowed(l, c, i)):  
                self.board[l][c] = i    
                #self.print_stack()       #imprime a pilha a cada alteração
                self.debug(index + 1)    # continua mesmo encontrando solução, não retorna true  
        self.board[l][c] = 0
        return False

    def create(self, index = 0):
        if index == len(self.places): 
            return True
        l, c = self.places[index]
        for i in sample(range(1,10), 9):         # cria uma lista aleatória de números de 1 a 9
            if(self.allowed(l, c, i)):  
                self.board[l][c] = i   
                #self.print_stack()
                if self.create(index + 1):  
                    return True            
        self.board[l][c] = 0              
        return False


# simple solve
board = Board(one_solution_board)
board.print_board()
board.solve()
print("\n\n")
board.print_board()
print("\n\n")

# two solutions solve
board = Board(two_solution_board)
board.print_board()
board.debug()
print("\n\n")
board.print_board()
print("solutions found: ", board.solutions)

# create mode
board = Board([[0 for _ in range(9)] for _ in range(9)])
board.create()
board.print_board()

