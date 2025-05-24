# Editor de texto

![_](https://raw.githubusercontent.com/qxcodeed/arcade/master/base/editor/cover.jpg)

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

## Testes

```txt
>>>>>>>>
abc
========
abc|
<<<<<<<<

>>>>>>>>
euRteRamo
========
eu
te
amo|
<<<<<<<<

>>>>>>>>
euRamo<<<
========
eu
|amo
<<<<<<<<

>>>>>>>>
euRamo<<<<<<<como-
========
como-|eu
amo
<<<<<<<<


>>>>>>>>
euRemo<<Ba>>>>>>
========
eu
amo|
<<<<<<<<

>>>>>>>>
voc-ae<<v<<e>>>Di>
========
voce-vai|
<<<<<<<<
```
