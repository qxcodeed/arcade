#include "lib.h"

// Os elementos do tipo Pos podem ser 
// acessados com os atributos first e second

vector<Pos> get_neib(Pos p) {
  /* Essa função deve retornar um
     vetor com as posições dos vizinhos
     da posição p */
}

bool inside(vector<string>& mat, Pos p) {
  /* Essa função retorna uma booleana que
     diz se a posição p está dentro da
     matriz mat */
}

void queimar(vector<string>& mat, size_t l, size_t c) {
  /* Essa função deve usar uma list como pilha
     e marcar as árvores na matriz como
     queimados */

     /* Uma sugestão de como fazer isso é:
         - adicionar a primeira posição na pilha
         - marcar o elemento da matriz na
           posição do topo da pilha
         - adicionar seus vizinhos que podem
           ser queimados
         - repetir até que a pilha esteja vazia */
}
