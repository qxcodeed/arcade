#ifndef AMBIENT_H
#define AMBIENT_H

#include "state.h"
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
    void insertChar(char c){
        auto prox = itc;
        states.erase(++prox, states.end());
        states.push_back(*itc);
        itc = --states.end();

        itc->text.insert(itc->cursor, c);
    }
    void sendBackspace(){
        if(itc->cursor != itc->text.begin())
            itc->cursor = itc->text.erase(--itc->cursor);
    }
    void sendDelete(){
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

#endif