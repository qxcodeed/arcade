# Editor com Control Z

![_](assets/capa.jpg)

Implementar um editor de texto simplificado que receba os seguintes valores como
entrada.

- Os caracteres minúsculos "abc...z" e "-" são compreendidas como texto.
- O cursor deve ser mostrado com o char |
- Os seguintes caracteres serão comandos.
  - __Parte 1__ - Movimentação de Cursor
    - "R" return, insere o Enter.
    - "B" backspace, apaga o caractere atrás do cursor, se houver.
    - "D" delete, apaga o caractere na frente do cursor, se houver.
    - ">" move o cursor para direita, se for possível.
    - "<" move o cursor para esquerda, se for possível.
  - __Parte 2__ - Fila de ações.
    - "Z" Desfazer, desfaz a inserção ou remoção.
    - "Y" Refazer, refaz a última inserção ou remoção.
  
## Exemplos

<!-- load tests.toml --tests 4 -->
```py
>>>>>>>> INSERT
abc
======== EXPECT
abc|
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
euRteRamo
======== EXPECT
eu
te
amo|
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
euRamo<<<
======== EXPECT
eu
|amo
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
euRamo<<<<<<<como-
======== EXPECT
como-|eu
amo
<<<<<<<< FINISH
```
<!-- load -->
