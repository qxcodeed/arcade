# Investindo em ativos digitais

Suarez conheceu o maravilhoso mundo dos ativos digitais. Seu patrimônio cresceu bastante usando a seguinte estratégia de investimento.

Considere que Suarez possui N reais para
investir e ele nunca investe mais do que K reais em um mesmo ativo digital com o objetivo de diversificar sua carteira e reduzir o risco. Se N > K, Suarez divide seu capital em duas partes de $\lceil N/2 \rceil$
e $\lfloor N/2 \rfloor$ reais e continua dividindo cada uma dessas partes de maneira similar, até resultar em partes de no máximo K reais cada. Ao final desse processo, Suarez terá seu capital dividido em E partes e investirá integralmente cada uma delas em ativos digitais diferentes. Sua tarefa consiste em ajudar Suarez a descobrir em quantos ativos digitais diferentes ele irá investir usando essa estratégia.

Por exemplo, considere N = 18 e K = 4. Após a primeira divisão João terá duas partes de 9 reais. Cada uma dessas partes será dividida, resultando em duas partes de 5 reais e duas partes de 4 reais. As partes de 5 reais são então divididas novamente, resultando em duas partes de 2 reais e duas partes de 3 reais. As partes de 4 reais não precisam mais ser divididas. Logo, todas as 6 partes resultantes (duas de 2 reais, duas de 3 reais e duas de 4 reais) possuem no máximo 4 reais e são utilizadas por João para investir em 6 ativos digitais distintos.

## Entrada

A entrada é composta por uma única linha contendo dois inteiros $n$ e $k$ respectivamente o capital inicial de Suarez (1 ≤ N ≤ 1.000.000) em reais e a quantidade máxima de reais (1 ≤ K ≤ 1.000.000) que Suarez pode investir para comprar ações de uma mesma empresa.

## Saída

A saída é composta por uma única linha contendo um único número, a quantidade de empresas E em que Suarez irá investir seu capital.

## Exemplo de Entrada

```txt
18 4
```

## Exemplo de Saída

```txt
6
```
