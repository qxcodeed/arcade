## L1 - {interactive} Visualizando mat com xpaint {optional}
## @qxcode

Você pode utilizar esse código para gerar a visualização do seu labirinto com o utilizando a biblioteca de desenho que já está nessa pasta.

![](lab.png)

Nesse caso, a figura é carregada do arquivo de texto com o labirinto.

Você pode compilar o código e passar o seu labirinto em txt por parâmetro.

Seu arquivo de texto deve ter as dimensões na primeira linha e o labirinto deve ser composto de '#' e ' ' tal qual o arquivo exemplo da pasta.

```
gcc -Wall make_img.c -o make_img
./make_img seu_lab.txt
```
