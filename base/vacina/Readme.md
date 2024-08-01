# L0 - @vacina

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Tests](#tests)
-- | -- | --
<!-- toch -->

## Intro

Um novo vírus mortal está infectando uma grande população de um planeta. Um brilhante cientista chamado Wladimir descobriu uma nova cepa de vírus que pode curar essa doença. A vacina produzida a partir desse vírus tem várias potências, dependendo da contagem de células T. Uma pessoa é curada somente se a contagem de células T na vacina for maior do que a contagem de células T da pessoa.

Um médico recebe um conjunto de relatórios contendo a contagem de células T de cada paciente infectado. O laboratório QuixaVax armazena todas as vacinas que o médico possui e suas respectivas contagens de células T. Você precisa determinar se o médico pode salvar todos os pacientes com as vacinas disponíveis. Note que o número de vacinas e pacientes é igual.

## Draft

- Você deve implementar um algoritmo de ordenação e a função `vacinou` no arquivo `main.cpp`.

<!-- links .cache/draft -->
- cpp
  - [main.cpp](.cache/draft/cpp/main.cpp)
<!-- links -->

## Tests

### Entrada

- A primeira linha contém um número inteiro N, representando o número de vacinas e pacientes.
- A segunda linha contém N inteiros, representando a contagem de células T de cada vacina.
- A terceira linha contém N inteiros, representando a contagem de células T de cada paciente.

### Saída

- Imprima uma única linha contendo Yes, se todos os pacientes podem ser salvos, e No, caso contrário.

### Exemplos

```txt
>>>>>>>>
5
123 146 454 542 456
100 328 248 689 200
========
No
<<<<<<<<
```

> **Explicação**:
>
> - A vacina 1 (contagem 123) cura o paciente 1 (contagem 100).
>
> - A vacina 2 (contagem 146) não cura nenhum outro.

```txt
>>>>>>>>
5
123 690 454 150 456
100 328 248 689 145
========
Yes
<<<<<<<<
```

> **Explicação**:
>
>A vacina 1 (contagem 123) cura o paciente 1 (contagem 100).
>
> A vacina 2 (contagem 690) cura o paciente 4.
>
> A vacina 3 (contagem 454) cura o paciente 2.
>
> A vacina 4 (contagem 150) cura o paciente 5.
>
> A vacina 5 (contagem 150) cura o paciente 3.
