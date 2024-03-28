# Coeficientes @binomiais

- Veja a versão online: [aqui.](https://github.com/qxcodeed/arcade/blob/master/base/binomiais/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down ed binomiais`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

Os coeficientes binomiais são muito importantes para a resolução de vários problemas de contagem. Por exemplo,

`C(n,k)` representa o número de maneiras de escolher `k` elementos de um conjunto de n elementos.

`C(n + k - 1,k)` representa o número de maneiras de escolher `k` elementos de um conjunto de n elementos se repetições são permitidas.

Os coeficientes binomiais podem ser definidos usando a seguinte recursão:

<img src="https://latex.codecogs.com/svg.latex?C(n,k) = \begin{cases}1& ,k=0\\
1 & ,k=n\\ C(n-1,k-1) + C(n-1, k)&,   1\leq k \leq n-1\end{cases}">

Sua tarefa é dado dois inteiros n e k, calcula C(n,k).

**Entrada**

A primeira linha contendo dois inteiros n e k.

**Saída**

Imprima uma linha contendo C(n,k).


**Exemplo de Entrada**
```
8 4
```

**Exemplo de Saída**
```
70
```













