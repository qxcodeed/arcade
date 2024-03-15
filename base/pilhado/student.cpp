#include "lib.h"

// Use a função get(mat, pos) para acessar e 
// atribuir o valor da matriz(mat) na posição(pos) especificada

// Para acessar a linha e a coluna do tipo Pos 
// use os atributos c e l

vector<Pos> get_vizinhos(Pos p) {
    /* Essa função deve retornar um vetor
       com as posições vizinhas da
       posição p */
}

void procurar_saida(vector<string>& mat, Pos inicio, Pos fim) {
    /* Essa função deve marcar o caminho
       entre o inicio e fim com o char '.'
       usando uma pilha
    */

    /* Uma sugestão de como fazer isso é:
        - adicionar a primeira posição a pilha
        - marcar a posição do topo da pilha
          caso a posição esteja vazia
        - adicionar os seus vizinhos que estão
          vazios na pilha
        - caso não haja vizinhos vazios marque como vazia e
          desempilhe a pilha até que a posição
          no topo da pilha tenha um novo caminho
          ou seja:
            - enquanto o topo da lista for vizinho da
              posição anterior ao topo da lista
              desempilhe e marque a posição como
              vazia, caso contrário passe para
              a próxima iteração
        - repetir até encontrar o fim do labirinto
    */
}