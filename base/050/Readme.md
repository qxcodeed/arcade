## Match Strings

Há um vector de strings de entrada e um vector de strings de consulta. Para cada sequência de consultas, determine quantas vezes isso ocorre na lista de sequências de entrada.

Por exemplo, dada  **entrada = ['ab','ab','abc' ]** e **consultas = ['ab','abc','bc']**, encontramos 2 instâncias de **'ab'** , 1 de **'abc'** e 0 de **'bc'**. Para cada consulta, adicionamos um elemento ao nosso vector de retorno. 

**Descrição da função**

Complete a função *matchingStrings*. A função deve retornar um vector de números inteiros representando a frequência de ocorrência de cada sequência de consultas em *sequências* .

matchingStrings possui os seguintes parâmetros:

- *strings* - uma matriz de strings para pesquisar
- *consultas* - uma matriz de cadeias de consulta

**Formato de entrada**

A primeira linha contém e número inteiro , o tamanho de . Cada uma das próximas linhas contém uma sequência . A próxima linha contém , o tamanho de . Cada uma das próximas linhas contém uma sequência . 

**Formato de saída**

Retorne um vector inteiro dos resultados de todas as consultas em ordem.

**Entrada de amostra**

```
>>>>>>>> 01
4 
aba 
baba 
aba 
xzxb 
3 
aba 
xzxb 
ab
========
2 1 0
<<<<<<<<
```

## Código inicial

```cpp
#include <bits/stdc++.h>

using namespace std;

// Complete a funcao matchingStrings.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    //Seu codigo aqui
    
}

int main()
{

    int strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (int i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];

        if (i != res.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

    return 0;
}

```



