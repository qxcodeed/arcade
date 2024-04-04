# L1 - @sufixos - Imprimindo palavra em pedaços

Você precisa responder algumas questões fundamentais antes de começar o desenvolvimento de um algoritmo recursivo. Entre elas, temos:

* Qual é o caso base?
* Qual é a ação fundamental?
* Quantas vezes teremos uma chamada recursiva.

Considere o seguinte padrão impressão:

```txt
4
3
2
1
```

No exemplo acima, estamos imprimindo todos os números em ordem decrescente de 4 até 1. Neste exemplo, vamos considerar que o caso base acontece quando o valor de n é igual a 0. A ação fundamental será imprimir um número e depois resolver o mesmo problema para o número anterior.

```c
void countDown(int n) {
    if (n == 0) {
        return ;
    }
    cout << n << endl;
    countDown(n-1);
}
```

Considere agora o seguinte padrão de impressão:

```txt
4
3
2
1
1
2
3
4
```

Esse padrão pode ser reproduzido pelo seguinte programa:

```c
void countDownUp(int n) {
    if (n == 0) {
        return ;
    }
    cout << n << endl;
    countDownUp(n-1);
    cout << n << endl;
}
```

Já o padrão de impressão:

```txt
wladimir
ladimir
adimir
dimir
imir
mir
ir
r
```

O padrão pode ser reproduzido pelo seguinte programa:

```c
void printTower(char * s) {
    if (*s == '\0') {
        return;
    }
    printf("%s\n", s);
    printTower(s+1);
}
```

Faça um program que imprima todos os sufixos de uma palavra do menor sufixo até o maior.

## Entrada

A entrada é composta por uma única linha contendo uma palavra com até 100 caracteres.

## Saída

A saída é composta por `n` linhas sendo `n` o tamanho da palavra lida.

## Exemplo de Entrada

```txt
wladimir
```

## Exemplo de Saída

```txt
r
ir
mir
imir
dimir
adimir
ladimir
wladimir
```
