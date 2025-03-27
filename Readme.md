# Repositório de exercícios para Estrutura de Dados

Esse é um repositório que integra o conteúdo das atividades de Estrutura de Dados (ES) para os cursos:

- Ciência da Computação
- Engenharia de Computação
- Sistemas de Informação
- Engenharia de Software

Esse curso apresenta os fundamentos teóricos e atividades práticas para a compreensão de como funcionam as estruturas de dados básicas e como utilizá-las para resolver problemas computacionais.

A linguagem escolhida para o curso é o C++, pois permite uma compreensão melhor das estruturas de baixo nível, como gestão da memória e um nível de controle que permite controlar e compreender a complexidade dos algoritmos.

O prérequisito para o curso é ter conhecimento básico de programação e lógica de programação, em linguagem C, C++, ou Python.

Cada grande bloco é composto de várias grupos, chamados de missões. Uma missão representa a aquisição de um conhecimento ou habilidade específica. Cada missão é composta de várias atividades, chamadas de tarefas. Uma tarefa pode ser uma leitura, vídeo, exercício teórico ou prática. Algumas atividades de código estão no modelo de maratona, com casos de testes que avaliam se o código resolve o problema proposto.

Para baixar as atividades, marcar as atividades feitas e executar os códigos de teste, você pode utilizar o aplicativo tko.

O próprio aplicativo vai orientar a sequência sugerida na qual as atividades devem ser realizadas e o mínimo a ser obtido para avançar para as próximas missões.

Bom trabalho.

## Introdução ao C++ e ED

Significado das tags nas questões:

| marcador  | significado
| --------- | -----------
| test      | Problema de código com testes
| open      | Problema de programação abertos sem testes
| info      | Conteúdo informativo de leitura ou vídeo
| task      | Outras atividades

### Conceitos Básicos de C++

Nesse primeiro bloco, vamos aprender ou relembrar os conceitos básicos da linguagem C++.

- [ ] `#cpp_intro   :info`[Objetivos Introdução](wiki/video_intro.md)
- [ ] `#cpp_pointer :info`[Vídeo - Qual a diferença entre ponteiros e referências](https://youtu.be/uz_sTcNdguY?si=YznFcnV6sisot_Sc)
- [ ] `#cpp_oop     :info`[Vídeo - Introdução a OOP in C++](https://youtu.be/w7F587dNwqA?si=2UMhfS9_DcAh-gjF)
- [ ] `#cpp_acesso  :info`[Vídeo - Modificadores de Acesso com exemplos](https://youtu.be/n1RfuPbzG-M?si=kwaSjo9Ng1g4waOK)

### Aprendendo um pouco sobre OOP em C++ <!-- @tad r:intro -->

A implementação de Orientação a Objetos em C++ tem várias peculiaridades como a forma de fazer o "toString" ou a sobrecarga de operadores e métodos.

- [ ] `#cpp_cpref  :info`[Como fazer sobrecarga de cópia e referencia](wiki/tad/sobrecarga.md)
- [ ] `#cpp_oper   :info`[Sobrecarga de operadores de classes](wiki/tad/sobrecarga_operadores.md)
- [ ] `L2 @ponto   :test`[Implemente a classe ponto](base/ponto/Readme.md)
- [ ] `L2 @fracao  :test`[Implemente a classe fração reduzida](base/fracao/Readme.md)

### Análise de Algoritmos <!-- @analise r:intro -->

A análise de algoritmos é essencial para entender e avaliar a eficiência das soluções computacionais. Ela permite medir o desempenho dos algoritmos em termos de tempo e espaço, facilitando a comparação entre diferentes abordagens para a mesma tarefa. Compreender a complexidade computacional ajuda a tomar decisões informadas sobre qual algoritmo utilizar, otimizando recursos e melhorando a performance do sistema.

Estudar análise de algoritmos também revela os limites e aplicabilidades de cada solução, evitando o uso inadequado e promovendo a criação de algoritmos mais eficientes e inovadores. Esse conhecimento é crucial não apenas para a resolução de problemas reais, mas também para o desenvolvimento de software otimizado e para a preparação em entrevistas técnicas, onde a análise de algoritmos é frequentemente testada.

- [ ] `#analise    :info`[Análise de Algoritmos](wiki/analise/analise.md)

## Recursão

Nesse bloco, abordaremos o conceito de recursividade, uma técnica de programação que permite que uma função chame a si mesma para resolver problemas de forma mais elegante e eficiente. Entender recursividade pode ajudar a simplificar problemas complicados e tornar a programação mais fácil e eficaz.

### Recursão: Estudo <!-- @rec_intro r:intro -->

- [ ] `#cpp_rec_view :info`[Vídeo - Introdução à recursão](https://youtu.be/nEohgkZkm_c?si=XIDgq6jPKlAd9gbz)
- [ ] `#cpp_rec_read :info`[Recursividade](wiki/recursao/recursao.md)

### Recursão: Treinando conceitos I<!-- @con_rec r:rec_intro -->

- [ ] `#cpp_intro       :info` [L0 - @binomiais - Calculando coeficientes](base/binomiais/Readme.md)
- [ ] `L0 @escada       :test` [De quantas maneiras podemos subir](base/escada/Readme.md)
- [ ] `L1 @diagonal     :test` [Imprimindo um char por linha](base/diagonal/Readme.md)
- [ ] `L1 @padroes1     :test` [Descobrindo quantos bloquinhos](base/padroes1/Readme.md)
- [ ] `L1 @sufixos      :test` [L1 - @sufixos - Imprimindo palavra em pedaços](base/sufixos/Readme.md)
- [ ] `L1 @empilhamento :test` [Empilhamento de divisões](base/empilhamento/Readme.md)
- [ ] `L2 @mdc          :test` [Implemente o mdc recursivo](base/mdc/Readme.md)

### Recursão: Treinando conceitos II <!-- @rec_basic r:con_rec -->

- [ ] `L2 @padroes2     :test`[Descobrindo quantas pecinhas](base/padroes2/Readme.md)
- [ ] `L2 @santo JM     :test`[O milagre de ficar pobre](base/santo/Readme.md)
- [ ] `L2 @fibonacci    :test`[Procriando coelhos](base/fibonacci/Readme.md)
- [ ] `L2 @quadrado     :test`[Aragão calculando n ao quadrado](base/quadrado/Readme.md)
- [ ] `L2 @bitcoin      :test`[Investindo em ativos digitais](base/bitcoin/Readme.md)

### Recursão: Desafios <!-- @rec_desafios r:rec_basic t:7 -->

- [ ] `L1 @triangulo   :test`[Imprimindo ao contrário](base/triangulo/Readme.md)
- [ ] `L3 @fibonacci2  :test`[Fazendo filhos e morrendo](base/fibonacci2/Readme.md)
- [ ] `L3 @padroes3    :test`[Contando pontos](base/padroes3/Readme.md)
- [ ] `L2 @queimada    :test`[Tocando fogo na floresta](base/queimada/Readme.md)
- [ ] `L2 @treinando   :test`[Treinando recursão com vetores](base/treinando/Readme.md)

### Recursão: Exercícios com matemática <!-- @rec_primos r:rec_basic -->

- [ ] [L1 - @eh_primo - Retorna se é ou não é](base/eh_primo/Readme.md)
- [ ] [L2 - @enesimo - Gere o enesimo primo](base/enesimo/Readme.md)
- [ ] [L2 - @priminhos - Carrega a lista de primos](base/priminhos/Readme.md)

### Recursão: Backtracking <!-- @backtracking r:rec_desafios -->

- [ ] [L2 - escapando do @labirinto](base/labirinto/Readme.md)
- [ ] [L2 - @distancia](base/distancia/Readme.md)
- [ ] [L3 - @sudoku](base/sudoku/Readme.md)

## Ordenação

Nesse bloco, abordaremos os algoritmos de busca e ordenação, duas técnicas essenciais na programação. Os algoritmos de busca são usados para encontrar elementos específicos dentro de uma estrutura de dados (localizar um nome específico em uma lista de contatos, por exemplo), enquanto os algoritmos de ordenação organizam esses elementos em uma sequência desejada (como organizar uma lista de livros por título em ordem alfabética). Compreender essas técnicas é crucial para manipular e acessar dados de forma eficiente em seus programas.

### Ordenação: Estudo <!-- @sort_intro r:analise -->

- [ ] `#alg_ord_video` [Vídeo - implementação de todos os algoritmos de ordenação](https://youtu.be/k6nODikH_D8?si=tpbDRg139HvdzSIS)
- [ ] `#alg_ord_leitura` [Algoritmos de Busca](wiki/busca_ordenacao/busca.md)
- [ ] `#alg_ord_simples`[Algoritmos de Ordenação](wiki/busca_ordenacao/ordenacao.md)
- [ ] `#alg_ord_recurs`[Algoritmos de Ordenação Recursiva: Merge Sort e Quick Sort](wiki/ordenacao_recursiva/ordenacao_rec.md)

### Ordenação: Construindo algoritmos <!-- @sort_build r:sort_intro -->

- [ ] [L3 - @tapioca Sort](base/tapioca/Readme.md)
- [ ] [L2 - @mergevet - Criando um vetor simples e fazendo um merge](base/mergevet/Readme.md)

### Ordenação: Resolvendo exercícios simples <!-- @sort_basic r:sort_intro -->

- [ ] [L0 - @vacina](base/vacina/Readme.md)
- [ ] [L1 - @indices do vetor](base/indices/Readme.md)

## Vetores <!-- group -->

Os vetores são estruturas de dados fundamentais que permitem acesso direto e rápido a qualquer elemento, tornando operações de leitura e escrita extremamente eficientes. Compreender como os vetores gerenciam a memória e os custos associados ao redimensionamento é essencial para tomar decisões informadas sobre seu uso. Além disso, os vetores são amplamente utilizados em diversas aplicações e são nativamente suportados por muitas linguagens de programação, o que facilita sua integração com outras partes do sistema. Para entender melhor o funcionamento da estrutura vamos trabalhar sua:

- Construção
- Utilização

### Vetores: Construindo <!-- @array_intro r:intro q:4 -->

- [ ] [L2 - implementando vector com @ponteiros](base/ponteiros/Readme.md)
- [ ] [L2 - implementando vector com @classes](base/classes/Readme.md)

### Vetores: Resolvendo Problemas Simples <!-- @array_basic r:array_intro -->

Treinando o uso da classe vector e seus métodos na resolução de problemas básicos.

- [ ] [L1 - @buscas de strings](base/buscas/Readme.md)
- [ ] [L1 - @rotacoes em uma lista](base/rotacoes/Readme.md)
- [ ] [L2 - @princesa v1](base/princesa/Readme.md)
- [ ] [L2 - princesa @alternando](base/alternando/Readme.md)

### Vetores: Otimizando problemas com maps e sets <!-- @array_struct r:array_basic -->

Os exercícios desse bloco podem ser resolvidos com vectors, porém a maioria das atividades precisa de atenção para a manipulação eficiente dos elementos. Estruturas como map, set, list e stack podem ser mais eficientes para resolver os problemas propostos.

- [ ] [L2 - @apagando elementos de forma eficiente](base/apagando/Readme.md)
- [ ] [L2 - @manipulacao - Utilizando a stl](https://github.com/qxcodepoo/arcade/blob/master/base/manipulacao/Readme.md)
- [ ] [L2 - @especiais - Utilizando map e set](https://github.com/qxcodepoo/arcade/blob/master/base/especiais/Readme.md)

## Listas <!-- group -->

Agora estudaremos as listas encadeadas, estruturas de dados flexíveis e eficientes que podem crescer e diminuir de tamanho facilmente, adaptando-se às necessidades de armazenamento dos elementos. Diferentemente dos vetores, que têm um tamanho fixo ou precisam ser redimensionados de forma custosa, as listas encadeadas não utilizam um espaço de armazenamento contínuo na memória. Elas são representadas por uma sequência de elementos ligados entre si, podendo ser simplesmente ou duplamente encadeadas, lineares ou circulares. Além disso, as listas encadeadas servem como base para a implementação de diversas outras estruturas de dados, como pilhas, filas e grafos. Para entender melhor o funcionamento da estrutura vamos trabalhar sua:

- Construção
- Utilização

### Lista: Construindo <!-- @list_build r:array_intro -->

- [ ] `#lista_video`[Vídeo - Implementando Lista Ligada Dupla](https://youtu.be/gA4YAtXnnKw?si=cC2aea_5N4cFUxJY)
- [ ] [L1 - implementando lista @ligada simples sem cabeça e rabo](base/ligada/Readme.md)
- [ ] [@lista_simples - Lista Simplesmente Encadeada](base/lista_simples/Readme.md)

### Lista: Resolvendo Problemas Simples <!-- @list_basic r:list_build -->

- [ ] [L2 - @princesa-lista](base/princesa-lista/Readme.md)
- [ ] [L2 - @princesa-lista-2 princesa alternando com lista](base/princesa-lista-2/Readme.md)

### Lista: Resolvendo Problemas Avançados <!-- @list_advanced r:list_basic -->

- [ ] [L3 - @banco - Gerenciando a fila](base/banco/Readme.md)
- [ ] [L2 - @editor de texto](base/editor/Readme.md)
- [ ] [L4 - @controlz - editor2](base/controlz/Readme.md)

## Pilha e Fila <!-- group -->

### Fila: Construindo <!-- @fila_build r:list_build -->

- [ ] [L1 - @fila como duas pilhas](base/fila/Readme.md)

### Pilha - Resolvendo problemas <!-- @pilha r:fila_build -->

- [ ] [L2 - @queimando árvores usando pilha](base/queimando/Readme.md)
- [ ] [L2 - fugindo do labirinto @pilhado](base/pilhado/Readme.md)
- [ ] [L1 - @polonesa - Transforme da notação padrão para polonesa reversa](base/polonesa/Readme.md)

### Fila - Resolvendo problemas <!-- @fila_solver r:fila_build -->

- [ ] [L1 - Gerenciando @chaves de disputas usando uma fila](base/chaves/Readme.md)
- [ ] [L2 - @caminhao abastecendo](base/caminhao/Readme.md)
- [ ] [L3 - menor @caminho entre dois pontos - floodfill pathfinding](base/caminho/Readme.md)

## Árvores <!-- group -->

### Árvore - Construindo <!-- @tree r:list_build -->

- [ ] [L2 - lendo uma árvore a partir de um @serial](base/serial/Readme.md)
- [ ] [L2 - mostrando a árvore @formatada](base/formatada/Readme.md)
- [ ] [L2 - @soma dos nós da árvore](base/soma/Readme.md)
- [ ] [L2 - @altura e profundidade da árvore](base/altura/Readme.md)
- [ ] [L2 - @arvore-path](base/arvore-path/Readme.md)
- [ ] [L2 - serialização @dividido](base/dividido/Readme.md)