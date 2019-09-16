# Detecção de ciclo

Diz-se que uma lista vinculada contém um *ciclo* se algum nó for visitado mais de uma vez enquanto estiver percorrendo a lista.

Complete a função fornecida em seu editor. Ele tem um parâmetro: um ponteiro para um objeto *Node* chamado que aponta para o início de uma lista vinculada. Sua função deve retornar um booleano indicando se existe ou não um ciclo na lista. Se não *é* um ciclo, volte *verdade* ; caso contrário, retorne *false* .

**Nota:** Se a lista estiver vazia, será *nulo* .

**Formato de entrada**

Nosso verificador de código oculto passa o argumento apropriado para sua função. Você não é responsável por ler nenhuma entrada do stdin.

**Formato de saída**

Se a lista contiver um ciclo, sua função deverá retornar *true* . Se a lista *não* contiver um ciclo, ela deverá retornar *false* . O número inteiro binário correspondente ao valor booleano retornado por sua função é impresso em stdout pelo nosso verificador de código oculto.

**Entrada de amostra**

As seguintes listas vinculadas são passadas como argumentos para sua função:

![Entradas de amostra](https://s3.amazonaws.com/hr-challenge-images/1163/1463778594-900a0ae522-inputs.png)

**Saída de amostra**

```
0
1
```

**Explicação**

1. A primeira lista não possui ciclo, portanto, retornamos *false*.
2. A segunda lista possui um ciclo, portanto, retornamos *true*.