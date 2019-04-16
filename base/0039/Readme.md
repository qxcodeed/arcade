## 08.6 Sort  Visualizando ordenação
## @qxcode

Os seguintes comandos podem ser utilizados para visualizar ordenação

```
// desenha uma linha vermelha no valor de referencia
void xs_pivot(int value); 

// marca visualmente com uma barra amarela a partição de trabalho corrente
// no intervalo fechado [begin, end]
void xs_partition(int begin, int end); 

// tal qual o printf, você consegue mostrar o vetor e marcar elementos
// específicos com cores
void xd_vet(int vet[], int size, const char * format, ...);

```

---
```c
#include <stdio.h>
#include "xpaint.h"
#include "xvet.h"

int main() {
    x_open(600, 300);

    int vet[15];
    int size = sizeof(vet)/sizeof(int);
    for(int i = 0; i < size; i++) //preenchendo o vetor
        vet[i] = 10 * (i + 1); 

    xs_pivot(vet[4]); //definindo o referencial (red line)
    xs_partition(1, 13); //marcando a partição  (yellow bar below)
    xd_vet(vet, size, ""); //mostrando o vetor sem marcar ninguém

    //marca 4 elementos respectivamente com red, green, blue, yellow
    for(int i = 1; i < size - 3; i++)
       xd_vet(vet, size, "rgby", i, i + 1, i + 2, 4);
    x_close();

    return 0;
 }

```