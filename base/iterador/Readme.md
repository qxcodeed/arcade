# Criando um iterador

Um iterador pode ser utilizado para esconder a forma como os elementos são organizados e acessados.

- É responsabilidade do iterador saber como chegar no próximo elemento.
- Saber se chegou ao fim da estrutura.
- Opcional dependendo da estrutura:
  - Saber como voltar para o elemento anterior.

Vamos criar iteradores para navegar em um vetor utilizando a sintaxe simplificada dos iteradores do Java.

Um iterador é criado a partir da estrutura a ser percorrida e possui dois métodos principais.

- hasNext(): bool, que informa se ainda tem algum elemento.
- next(): int, que pega o próximo elemento.

Os nomes mudam um pouco dependendo da linguagem utilizada. Veja o diagrama dos métodos a serem implementados e o exemplo nos arquivos `extra.md` e no rascunho da linguagem.

Você vai receber implementado um iterador que percorre a estrutura do início ao fim e deve implementar outros dois iteradores.

- ReverseIterator: percorre a estrutura do fim para o início.
- CyclicIterator: percorre a estrutura como se fosse uma lista cíclica infinita.

## Shell

```py
#TEST_CASE show
$read 1 4 2 3 5 6 9 7
$show
[ 1 4 2 3 5 6 9 7 ]
$end
```

```py
#TEST_CASE show
$read 1 4 2 3 5 6 9 7
$reverse
[ 7 9 6 5 3 2 4 1 ]
$end
```

```py
#TEST_CASE show
$read 1 2 3
$cyclic 10
[ 1 2 3 1 2 3 1 2 3 1 ]
$end
```
