# Princesa com lista ligada

[![_](assets/cover.jpg)](https://www.youtube.com/watch?v=uCsD3ZGzMgE)

Um problema bem interessante e antigo da matemática é conhecido como Josephus Problem. No link da imagem você pode, por curiosidades aprender bastantes sobre ele e o modelo matemático que se propõe a modelá-lo.

Nosso objetivo aqui será apenas implementar seu funcionamento.

___

No problema, **N** pessoas se colocam numa fila circular e assumem valores de 1 até **N**. Um número **E** é escolhido para iniciar o jogo. **E** pega a espada, mata o elemento à sua frente e passa a espada uma posição à frente. O jogo continua até que um único elemento permaneça vivo.

___

- Entrada:
  - Os valores de **N** e **E** na primeira linha.
- Saída:
  - Etapa a etapa, os elementos que estão vivos na fila circular, indicando com um > quem está com a espada.

___

## Implementação usando listas

Resolva novamente o problema utilizando

- a lista que vem embutida na sua linguagem ou sua própria lista para colocar os elementos
- use um iterator para rastrear a posição da espada
- use o método erase da lista para matar os elementos


## Testes

```toml
[[tests]]
input = '''
3 1
'''
output = '''
[ 1> 2 3 ]
[ 1 3> ]
[ 3> ]
'''
```
