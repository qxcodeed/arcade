#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <list>
#include <sstream>
using namespace std;

//State define uma lista de caracteres e um cursor que define onde o próximo caractere será inserido
//Se nosso text é "amor", e o cursor aponta para 'a', ao inserir o char 'p', o resultado será
//"pamor" com cursor ainda apontando para o 'a'.
//para inserir depois do 'r', o cursor deve apontar para text.end()

struct State{
    list<char> text;
    list<char>::iterator cursor;
    //cria um estado vazio com o cursor apontando pra text.end()
    State(){
        cursor = text.end();
    }
    //inicia o estado com um texto inicial
    State(string init){
        for(auto c : init)
            this->text.push_back(c);
        cursor = text.end();
    }
    //cria uma copia do estado, corrige o posicionamento do cursor da copia
    State(const State& other):
        text(other.text){
        this->cursor = this->text.begin();
        for(auto it = other.text.begin(); it != other.cursor; it++)
            this->cursor++;
    }
    //monta a string colocando um | na posicao do cursor
    string getText(){
        stringstream ss;
        for(auto it = text.begin(); it != text.end(); it++){
            if(it == cursor)
                ss << "|";
            ss << *it;
        }
        if(cursor == text.end())
            ss << "|";
        return ss.str();
    }
};

#endif