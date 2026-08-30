# Caminhao abastecendo

![_](assets/cover.jpg)

[](solver.cpp)

## Descrição da função

- Um bomba de gasolina é um lugar onde você pode abastecer seu veículo.
- Cada bomba possui uma quantidade limitada de gasolina.
- As bombas estão espalhada em alguns lugares de uma lista circular de tamanho `N` numeradas com índice de `0` a `N - 1`.

Você tem duas informações correspondentes a cada uma das bombas de gasolina:

- a quantidade de gasolina que determinada bomba de gasolina fornecerá e
- a distância dessa bomba de gasolina até a próxima bomba de gasolina.

Inicialmente, o caminhão começa vazio e você tem um tanque de capacidade infinita sem gasolina.

- Você pode começar o passeio em qualquer uma das bombas de gasolina.
- Calcule o primeiro ponto de onde o caminhão poderá completar o círculo.
- Considere que o caminhão irá parar em cada uma das bombas de gasolina.
- O caminhão percorrerá um quilômetro por cada litro de gasolina.

## Formato de entrada

- A primeira linha conterá o valor de N.
- As próximas N linhas conterão um par de números inteiros cada, isto é, a quantidade de gasolina que a bomba de gasolina fornecerá e a distância entre essa bomba de gasolina e a próxima bomba de gasolina.

## Formato de saída

Um número inteiro que será o menor índice da bomba de gasolina a partir da qual podemos iniciar o passeio de forma a completar o círculo.
## Exemplos

<!-- load tests.toml --tests 1 -->
```py
>>>>>>>> INSERT
3
1 5
10 3
3 4
======== EXPECT
1
<<<<<<<< FINISH
```
<!-- load -->
