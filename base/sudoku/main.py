#!/usr/bin/env python
# -*- coding: utf-8 -*-
from random import sample

class Board:
    def __init__(self):
        self.board = [[0 for _ in range(9)] for _ in range(9)]

    def init_from_list(self, board: list[list[int]]):
        self.board = [row.copy() for row in board]
        return self

    def clone(self):
        return Board().init_from_list(self.board)

    def print_board(self):
        print("---------------------------------------")
        for l in range(9):
            if(l % 3 == 0 and l != 0):
                print(23 * "-")
            for c in range(9):
                if(c % 3 == 0 and c != 0):
                    print(" |", end="")
                print("", self.board[l][c], end="")
            print("")
        
    def get_lin(self, index: int) -> list[int]:
        return self.board[index]
    
    def get_col(self, index: int) -> list[int]:
        return [self.board[l][index] for l in range(9)]

    def get_box(self, lin: int, col: int) -> list[int]:
        l = (lin // 3) * 3# divisão inteira
        c = (col // 3) * 3
        return self.board[l][c:c + 3] + self.board[l + 1][c:c+3] + self.board[l + 2][c:c+3]

    def allowed(self, l: int, c: int, value: int) -> bool:
        return (not value in self.get_lin(l)) and (not value in self.get_col(c)) and (not value in self.get_box(l, c))
    
    def solve(self, index: int = 0) -> bool:
        l = index // 9
        c = index % 9
        if index == 81: 
            return True
        if self.board[l][c] != 0:
            return self.solve(index + 1)
        for i in range(1,10):         # de 1 ate 9
            if(self.allowed(l, c, i)):  # se posso colocar esse numero nessa posicao
                self.board[l][c] = i    # coloco o número
                if self.solve(index + 1):  # invoco a recursão pro proximo
                    return True            # se retornou true, então terminamos, para na primeira solução encontrada
        self.board[l][c] = 0               # se nenhum valor deu certo, coloco 0 e retorno false
        return False

    def count_solutions(self, index: int = 0, solutions: int = 0) -> int:
        l = index // 9
        c = index % 9
        if index == 81: 
            return solutions + 1
        if self.board[l][c] != 0:
            return self.count_solutions(index + 1, solutions)
        for i in range(1,10):         
            if(self.allowed(l, c, i)):  
                self.board[l][c] = i    
                solutions = self.count_solutions(index + 1, solutions)    # continua mesmo encontrando solução, não retorna true  
        self.board[l][c] = 0
        return solutions

    def create(self, index: int = 0) -> bool:
        l = index // 9
        c = index % 9
        if index == 81: 
            return True
        if self.board[l][c] != 0:
            return self.create(index + 1)
        for i in sample(range(1,10), 9):         # cria uma lista aleatória de números de 1 a 9
            if(self.allowed(l, c, i)):  
                self.board[l][c] = i   
                if self.create(index + 1):  
                    return True            
        self.board[l][c] = 0              
        return False



# create mode
board = Board()
board.create()
board.print_board()
print(board.count_solutions())

posicoes = sample(list(range(81)), 81)

for i in range(81):
    l = posicoes[i] // 9
    c = posicoes[i] % 9
    clone = board.clone()
    clone.board[l][c] = 0
    if clone.count_solutions() == 1:
        board.board[l][c] = 0
        print("removendo linha", l, "coluna", c)

board.print_board()
print(board.count_solutions())
