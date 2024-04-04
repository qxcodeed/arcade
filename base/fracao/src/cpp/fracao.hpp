#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

/*
Representa uma fração reduzida, ou seja, numerador e denominador são primos entre si.  
*/


class Frac {
   int num;
   int den;

    //========== TODO =====================
    // calcula o mdc
    static int mdc(int a, int b); //TODO
    // realiza a redução da fração
    void reduce();                //TODO 

public:
    //========== TODO =====================
    bool operator>(const Frac& other) const;  // TODO
    bool operator==(const Frac& other) const; // TODO
    Frac operator+(const Frac& other) const;  // TODO

    //========== FEITO ====================
    // TODOS OS CONSTRUTORES ESTÃO IMPLEMENTADOS
    // Construtor principal
    // Ele copia os valores de n e d para num e den
    // e chama o método reduce
    Frac(int n = 0, int d = 1): num(n), den(d) {
        this->reduce();
    }
    // Construtor de cópia
    // Ele está encaminhando a chamada para o construtor principal
    Frac(const Frac& other) : Frac(other.num, other.den){
    }
    
    // Só por curiosidade, esse é o operador de atribuição
    // Ele permite fazer a = b = c
    // Diferente do construtor, ele não cria um novo objeto, 
    // mas sim modifica o objeto existente
    Frac& operator=(const Frac& other) {
        this->num = other.num;
        this->den = other.den;
        this->reduce();
        return *this;
    }

    // Só por curiosidade, esse é o método canônico de comparação
    // Ele é menor, se não for maior e nem igual
    bool operator<(const Frac& other) const {
        return !(*this > other || *this == other);
    }
    int getNum() const { return num; }    
    int getDen() const { return den; } 

    std::string str() const {
        return std::to_string(num) + "/" + std::to_string(den);
    }

    // Operador de saída
    // Escreve a fração no formato num/den
    // Permite escrever a fração diretamente em um stream de saída
    // Ex: std::cout << Frac(1, 2) << std::endl;
    friend std::ostream& operator<<(std::ostream& os, const Frac& f) {
        return os << f.str();
    }
};

//========== TODO =====================
// função que ordena uma fração
// você pode usar a função std::sort
// ou implementar um algoritmo de ordenação
void ordena_frac(std::vector<Frac>& vet); //TODO
