# Como fazer sobrecarga de cópia e referencia

## Seja esse nosso código de referencia a ser estudado

<!-- load tad.cpp fenced -->

```cpp
#include <iostream>

class Foo {

    int x;


public:

    Foo(int value = 0) {
        x = value;
    }

    // esse método é chamado quando posso alterar o objeto
    int& getX() { 
        std::cout << "obtendo por referencia\n";
        return x;
    }

    // esse método é chamado quando não posso alterar o objeto
    int getX() const {
        std::cout << "obtendo por valor\n";
        return x;
    }
};

int main() {
    Foo f(5);
    f.getX() = 10; // chama o método int& getX()
    std::cout << f.getX() << '\n'; // 10

    const Foo f2(5);
    // f2.getX() = 10; // erro de compilação
    std::cout << f2.getX() << '\n'; // 5
}
```

<!-- load -->

Este código em C++ demonstra a sobrecarga de métodos e o uso de qualificadores de const para objetos. Vamos explorar os componentes e conceitos fundamentais para entender o código.

### Estrutura Básica do Código

O código é composto pelas seguintes partes principais:

1. **Inclusão da biblioteca `iostream`**: Necessária para usar `std::cout` para saída de dados.
2. **Definição da classe `Foo`**: Uma classe simples que contém um membro de dados privado `x` e dois métodos `getX` sobrecarregados.
3. **Função `main`**: Ponto de entrada do programa onde objetos da classe `Foo` são criados e utilizados.

### Classe `Foo`

A classe `Foo` possui:

- **Membro de dados privado `x`**: Uma variável inteira que será manipulada através dos métodos da classe.
- **Construtor**: Um método especial que é chamado quando um objeto da classe `Foo` é criado. O construtor inicializa o valor de `x` com o valor fornecido ou com 0 se nenhum valor for passado.

```cpp
class Foo {
    int x;

public:
    Foo(int value = 0) {
        x = value;
    }
```

### Métodos `getX`

A classe `Foo` possui dois métodos `getX` sobrecarregados, que diferem pelo qualificador `const`:

1. **Método não constante**: Permite alterar o valor de `x` retornando uma referência a `x`.
2. **Método constante**: Não permite alterar o valor de `x`, retornando uma cópia de `x`.

```cpp
    int& getX() { 
        std::cout << "obtendo por referencia\n";
        return x;
    }

    int getX() const {
        std::cout << "obtendo por valor\n";
        return x;
    }
};
```

### Função `main`

Na função `main`, dois objetos da classe `Foo` são criados e os métodos `getX` são chamados para demonstrar seu comportamento:

1. **Objeto não constante `f`**: Chamando `f.getX()`, o método não constante é invocado. Ele retorna uma referência, permitindo a modificação do valor de `x`.
2. **Objeto constante `f2`**: Chamando `f2.getX()`, o método constante é invocado, retornando uma cópia de `x`. Tentar modificar `x` através de `f2` resulta em um erro de compilação.

```cpp
int main() {
    Foo f(5);
    f.getX() = 10; // chama o método int& getX()
    std::cout << f.getX() << '\n'; // 10

    const Foo f2(5);
    // f2.getX() = 10; // erro de compilação
    std::cout << f2.getX() << '\n'; // 5
}
```

### Resumo

- **Sobrecarrega de métodos**: O C++ permite definir múltiplas funções com o mesmo nome, mas com diferentes assinaturas (parâmetros e qualificadores de const).
- **Qualificador `const`**: Indica que um método não pode modificar o estado do objeto, útil para garantir a imutabilidade de objetos constantes.
- **Referências vs Valores**: Métodos podem retornar referências ou valores. Retornar uma referência permite modificar o objeto original, enquanto retornar um valor cria uma cópia.

Compreender esses conceitos é fundamental para manipular objetos de forma eficiente e segura em C++.