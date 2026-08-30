# Otimizando vacinas

<!-- toch -->
[Intro](#intro) | [Exemplos](#exemplos)
-- | --
<!-- toch -->

## Intro

Um novo vírus mortal está infectando uma grande população de um planeta. Um brilhante cientista chamado Wladimir descobriu uma nova cepa de vírus que pode curar essa doença. A vacina produzida a partir desse vírus tem várias potências, dependendo da contagem de células T. Uma pessoa é curada somente se a contagem de células T na vacina for maior do que a contagem de células T da pessoa.

Um médico recebe um conjunto de relatórios contendo a contagem de células T de cada paciente infectado. O laboratório QuixaVax armazena todas as vacinas que o médico possui e suas respectivas contagens de células T. Você precisa determinar se o médico pode salvar todos os pacientes com as vacinas disponíveis. Note que o número de vacinas e pacientes é igual.

### Entrada

- A primeira linha contém um número inteiro N, representando o número de vacinas e pacientes.
- A segunda linha contém N inteiros, representando a contagem de células T de cada vacina.
- A terceira linha contém N inteiros, representando a contagem de células T de cada paciente.

### Saída

- Imprima uma única linha contendo Yes, se todos os pacientes podem ser salvos, e No, caso contrário.

## Exemplos

<!-- load tests.toml --tests 3 -->
```py
>>>>>>>> INSERT
5
10 61 55 88 17
15 76 21 73 19
======== EXPECT
No
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
5
123 146 454 542 456
100 328 248 689 200
======== EXPECT
No
<<<<<<<< FINISH
```

```py
>>>>>>>> INSERT
5
123 690 454 150 456
100 328 248 689 145
======== EXPECT
Yes
<<<<<<<< FINISH
```
<!-- load -->
