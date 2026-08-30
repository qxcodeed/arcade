# Instalação

- Após baixar a atividade pelo tko
- Navegue até a pasta da atividade pelo terminal
- cd ed/fractais_png/src/go
- Dê um ls e verá os arquivos `extra.md` e `main.go`
- Digite o seguintes comandos para iniciar o módulo e baixar a biblioteca de desenho

```bash
go mod init fractais
go get "github.com/fogleman/gg"
tko run *.go

# Abra o arquivo `image.png` para ver desenho gerado
code image.png
```

## Utilizando

A estrutura `Pen` simula uma caneta gráfica para desenhar em uma imagem 2D utilizando a biblioteca [`gg`](https://github.com/fogleman/gg). Ela permite movimentação com controle de direção, traçado de linhas, figuras geométricas e geração de arquivos PNG.

---

## 🔧 Funções e Métodos

### `func NewPen(width, height int) *Pen`

Cria uma nova instância de `Pen` com um canvas (`gg.Context`) do tamanho especificado.  
A caneta inicia no centro da tela, com a direção apontando para a direita (0 graus), com a caneta abaixada (`penDown = true`).

---

### `func (t *Pen) Walk(dist float64)`

Move a caneta `dist` unidades na direção atual.  
Se a caneta estiver abaixada (`penDown`), uma linha será desenhada entre o ponto atual e o novo ponto.

---

### `func (t *Pen) Left(deg float64)`

Gira a direção da caneta `deg` graus **no sentido anti-horário** (aumenta o ângulo).

---

### `func (t *Pen) Right(deg float64)`

Gira a direção da caneta `deg` graus **no sentido horário** (diminui o ângulo).

---

### `func (t *Pen) Up()`

Levanta a caneta.  
Próximos movimentos não desenharão linhas.

---

### `func (t *Pen) Down()`

Abaixa a caneta.  
Próximos movimentos desenharão linhas.

---

### `func (t *Pen) Goto(x, y float64)`

Move a caneta diretamente para as coordenadas `(x, y)`.  
Se estiver abaixada, desenha uma linha entre o ponto atual e o destino.

---

### `func (t *Pen) SetPosition(x, y float64)`

Move a caneta para as coordenadas `(x, y)` **sem desenhar**, independentemente do estado do `penDown`.

---

### `func (t *Pen) SetHeading(angle float64)`

Define a direção atual da caneta (em graus).  
0° aponta para a direita, 90° para cima, 180° para a esquerda, 270° para baixo.

---

### `func (t *Pen) DrawCircle(radius float64)`

Desenha o contorno de um círculo com o centro na posição atual e raio `radius`.  
Só desenha se a caneta estiver abaixada.

---

### `func (t *Pen) DrawRect(w, h float64)`

Desenha o contorno de um retângulo com largura `w` e altura `h`, com canto superior esquerdo na posição atual.  
Só desenha se a caneta estiver abaixada.

---

### `func (t *Pen) FillCircle(radius float64)`

Desenha e preenche um círculo com raio `radius`, centrado na posição atual.  
Só preenche se a caneta estiver abaixada.

---

### `func (t *Pen) FillSquare(w, h float64)`

Desenha e preenche um retângulo (ou quadrado) com largura `w` e altura `h`, com canto superior esquerdo na posição atual.  
Este método **ignora o estado de `penDown`**.

---

### `func (t *Pen) SetRGB(r, g, b float64)`

Define a cor da caneta com os valores RGB fornecidos (de 0 a 255).  
Exemplo: `SetRGB(255, 0, 0)` define a cor vermelha.

---

### `func (t *Pen) SetLineWidth(w float64)`

Define a espessura da linha usada para desenhar.

---

### `func (t *Pen) SavePNG(path string)`

Salva a imagem atual em um arquivo PNG com o nome e caminho fornecido.

---
