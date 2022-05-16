## L2 - {interactive} Distância: criação

![](__capa.jpg)

Tente criar um gerador de problemas Distância. Você pode seguir a seguinte sequência:

- Utilize argc e argv para receber o tamanho da string e o valor de distância desejado.

```
./solver 8 4

problema: 42..0..3. 4
resposta: 423104231
```
- Inicie a string com todos os valores vazios.
- Gere uma solução para essa string vazia, mas ao invés de testar os números sequencialmente de 0 a D em cada posição, coloque-os em um vetor e os embaralhe.
- Crie uma lista com todas as posições válidas da resposta e embaralhe.
    - para cada posição
        - se remover esse index, gerar apenas uma única solução para o problema, remova o index

