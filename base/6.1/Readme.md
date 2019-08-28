## @6.1 Lista Editor de texto                  #todo
## @qxcode

Implementar um editor de texto simplificado que receba os seguintes valores como
entrada.

- Os caracteres minúsculos "abc...z" e "-" são compreendidas como texto.
- Os seguintes caracteres serão comandos.
    - __Parte 1__ - Movimentação de Cursor
        * "R" return, insere o Enter.
        * "B" backspace, apaga o caractere atrás do cursor, se houver.
        * "D" delete, apaga o caractere na frente do cursor, se houver.
        * ">" move o cursor para direita, se for possível.
        * "<" move o cursor para esquerda, se for possível.
    - __Parte 2__ - Fila de ações.
        * "Z" Desfazer, desfaz a ultima ação
        * "Y" Refazer, refaz a ultima ação se houver
    - __Parte 3__ - Movimentação Avançada
        * "A" up, vai pra linha de cima na posição correspondente que for acessível.
        * "V" down, vai para linha de baixo na posição .


## Testes

```
>>>>>>>>
euRteRamo
========
<<<<<<<<

>>>>>>>>
euRamo<<<
========
<<<<<<<<

>>>>>>>>
euRamo<<<<<<<como-
========
<<<<<<<<


>>>>>>>>
euRemo<<Ba>>>>>>
========
<<<<<<<<
```

## Simulação 2
    voce-vai#
    #
    voc-ae<<v<<e>>>Di>
    
    voce-vai#

## Simulação 3

hoje fui

Se você implementar a **Parte 2** o undo e o redo funcionam como no seu editor. 
Pense na movimentação também como um comando. Cada Z volta um comando.

    #
    eu-te-amo#

    Z
    eu-te-am#

    B<
    eu-te-#a

    ZZ
    eu-te-am#

    RR
    eu-te-#a

    m>to
    eu-te-mato

Perceba que como no seu editor, se você der C-Z e depois escrever algo, você
perderá o que tinha escrito e não poderá mais dar redo.


```cpp

struct Ambient{
    list<char> texto;
    list<char>::iterator cursor;
};

struct Editor{
    list<Ambient> linha_temporal;
    list<Ambient>::iterator estado_atual;
};




```