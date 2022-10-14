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

#include <iostream>
#include <list>
using namespace std;


struct Ambient{
    list<State> states;
    list<State>::iterator itc; //estado atual

    Ambient(string init_text = ""){
        states.push_back(State(init_text));
        itc = states.begin();
    }

    void controlZ(){
        if(itc != states.begin())
            itc--;
    }
    void controlY(){
        if(itc != prev(states.end()))
            itc++;
    }
    void pushState(){
        auto prox = itc;
        states.erase(++prox, states.end());
        states.push_back(*itc);
        itc = --states.end();
    }
    void insertChar(char c){
        pushState();
        itc->text.insert(itc->cursor, c);
    }
    void sendBackspace(){
        pushState();
        if(itc->cursor != itc->text.begin())
            itc->cursor = itc->text.erase(--itc->cursor);
    }
    void sendDelete(){
        pushState();
        if(itc->cursor != itc->text.end())
            itc->cursor = itc->text.erase(itc->cursor);
    }
    void sendUp(){
        int desloc = 0;
        auto it = itc->cursor;
        //volta pro comeco da linha contando quantos elementos são
        while(((*prev(it)) != '\n') && (prev(it) != itc->text.end())){
            desloc++;
            it--;
        }
        //se o comeco da linha é end, nao existe linha anterior, entao saia
        if(prev(it) != itc->text.end()){
            //como existe linha anterior, va ate o primeiro elemento dela
            do{
                it--;
            }while(((*prev(it)) != '\n') && (prev(it) != itc->text.end()));
            //tente andar desloc elementos, mas pare se encontrar o final
            for(int i = 0; i < desloc; i++){
                if(((*it) == '\n') || (it == itc->text.end()))
                    break;
                else
                    it++;
            }
            itc->cursor = it;
        }
    }
    void sendDown(){
        int desloc = 0;
        auto it = itc->cursor;
        //volta pro comeco da linha contando quantos elementos são
        while(((*prev(it)) != '\n') && (prev(it) != itc->text.end())){
            desloc++;
            it--;
        }
        do{
            it++;
        }while(((*prev(it)) != '\n') && (prev(it) != itc->text.end()));

        if(prev(it) != itc->text.end()){
            for(int i = 0; i < desloc; i++){
                if(((*it) == '\n') || (it == itc->text.end()))
                    break;
                else
                    it++;
            }
            itc->cursor = it;
        }
    }
    void sendLeft(){
        if(itc->cursor != itc->text.begin())
            itc->cursor--;
    }
    void sendRight(){
        if(itc->cursor != itc->text.end())
            itc->cursor++;
    }
};

// David Sena Oliveira
// versão: 3.0
// data: 26/06/2019




//funcao deve processar o evento alterando o estado atual e o buffer de estados.
void processKey(Ambient & amb, char tecla){
    if(tecla == 'Z') //control z
        amb.controlZ();
    else if(tecla == 'Y') //control y
        amb.controlY();
    else if(tecla == 'B')
        amb.sendBackspace();
    else if(tecla == 'D')
        amb.sendDelete();
    else if(tecla == '<')
        amb.sendLeft();
    else if(tecla == '>')
        amb.sendRight();
    else if(tecla == 'A')
        amb.sendUp();
    else if(tecla == 'V')
        amb.sendDown();
    else if(tecla == 'R')
        amb.insertChar('\n');
    else //alguma tecla printável
        amb.insertChar(tecla);
}

//########################################################
//############# FUNCAO MAIN ##############################
//########################################################

int main()
{
    
    string line;
    getline(cin, line);
    Ambient amb;
    for(auto c : line)
        processKey(amb, c);
    cout << amb.itc->getText() << endl;
    return 0;
}



