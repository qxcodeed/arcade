## 06.1 Lista Editor de texto                  #todo
## @qxcode

- Adicionar casos de teste para moodle
- Baixar 


Implementar um editor de texto simplificado que receba os seguintes valores como
entrada.

- Os caracteres minúsculos "abc...z" e "-" são compreendidas como texto.
- Os seguintes caracteres serão comandos.
    - __Parte 1__ - Movimentação de Cursor
        * ">" move o cursor para direita.
        * "<" move o cursor para esquerda.
        * "B" backspace, apaga o caractere atrás do cursor, se houver.
        * "D" delete, apaga o caractere na frente do cursor, se houver.
    - __Parte 2__ - Fila de ações.
        * "Z" Desfazer, desfaz a ultima acao
        * "R" Refazer, refaz a ultima ação se houver

## Simulação 1

Na simulação o # representa a posicao do cursor. O : representa a entrada de
dados do usuário seguinda de Enter. Se mais de um caractere for dado na entrada
processe todos os comandos.

    #
    e

    e#
    -

    e-#
    mo

    e-mo#
    <<

    e-#mo
    e

    e-e#mo
    <<

    e#-emo
    o

    eo#-emo
    B

    e#-emo
    u>

    eu-#emo
    Da

    eu-a#mo
    >>

    eu-amo#

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