#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

//=============================================================================
// Representa uma fração reduzida, numerador e denominador são primos entre si.  
//=============================================================================

class Frac {
   int num;
   int den;

//=============================================================================
//========  MÉTODOS AUXILIARES QUE JÁ ESTÃO IMPLEMENTADOS
//=============================================================================
public:
    Frac(int n = 0, int d = 1);               // Construtor
    std::string str() const;                  // toString
    int getNum() const { return num; }    
    int getDen() const { return den; } 

//=============================================================================
//===== MÉTODOS PARA VOCÊ IMPLEMENTAR NO ARQUIVO .cpp ===================
//=============================================================================
private:
    static int mdc(int a, int b);             //TODO - calcula o mdc
    void reduce();                            //TODO - realiza a redução da fração
public:
    bool operator<(const Frac& other) const;  // TODO - operador menor que
    bool operator==(const Frac& other) const; // TODO - operador igualdade
    Frac operator+(const Frac& other) const;  // TODO - operador de soma
};
void ordena_frac(std::vector<Frac>& vet);     //TODO - ordena um vector de fracoes

//=============================================================================
//======== IMPLEMENTAÇÕES QUE JÁ VIERAM FEITAS
//=============================================================================

// OBS IMPORTANTE: sempre que escrevemos uma função ou método no .h,
// ou ela deve estar dentro da classe, tal como foi feito com os
// métodos getNum e getDen, ou ela deve ser declarada como inline
// para não ter conflito no carregamento da lib por módulos diferentes.


// Construtor principal
// Ele copia os valores de n e d para num e den
// e chama o método reduce
inline Frac::Frac(int n, int d): num(n), den(d) {
    this->reduce();
}

// Gera uma string no formato num/den
inline std::string Frac::str() const {
    return std::to_string(num) + "/" + std::to_string(den);
}

// Operador de saída
// Permite escrever a fração diretamente em um stream de saída
// Ex: std::cout << Frac(1, 2) << std::endl;
inline std::ostream& operator<<(std::ostream& os, const Frac& f) {
    return os << f.str();
}
