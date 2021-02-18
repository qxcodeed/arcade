// David Sena Oliveira
// versão: 3.0
// data: 26/06/2019


#include <iostream>
#include <list>
#include <sstream>
#include "state.h"
#include "ambient.h"
using namespace std;


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



