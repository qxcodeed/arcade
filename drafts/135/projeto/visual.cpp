// David Sena Oliveira
// versão: 3.0
// data: 09/05/2019


#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "state.h"
#include "ambient.h"
#include "xfont.h"
using namespace std;

//se quiser escolher uma font específica, coloque na pasta
//e configure o path para font
//depois mude DEFAULT_FONT para 0
const string font_path = "ed_font.ttf";
#define DEFAULT_FONT 1

#define NEW_SFML_KEYS 0
#define NEW_SFML_COLOR 1

//prototipos
void processKey(Ambient& amb, sf::Event& event);
void draw_text(sf::RenderWindow& janela, string text);


//########################################################
//############# FUNCAO MAIN ##############################
//########################################################

int main()
{
    
    string texto_inicial = "Digite\nuse espaco\ndirecionais\nEnter.";
    Ambient amb(texto_inicial);

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
                processKey(amb, event);
            }
        }

        draw_text(janela, amb.itc->getText());
    }
    return 0;
}


//uma funcao feia, mas simples.
//pega alguns caracteres, inclusive separando maiúsculos.
//se a tecla nao corresponder a um char printável, retorna '\0'
char sf2char(sf::Event event){
    if(event.type != sf::Event::KeyPressed)
        return '\0';

    auto key = event.key.code;
    auto shift = event.key.shift;
    if((key >= sf::Keyboard::A)  and (key <= sf::Keyboard::Z))
        return (key - sf::Keyboard::A) + (shift? 'A' : 'a');
    else if((key >= sf::Keyboard::Num0) and (key <= sf::Keyboard::Num9))
        return key - sf::Keyboard::Num0 + '0';
    else if((key >= sf::Keyboard::Numpad0) and (key <=sf::Keyboard::Num9))
        return key - sf::Keyboard::Numpad0 + '0';
    else if(key == sf::Keyboard::LBracket)
        return shift ? '{': '[';
    else if(key == sf::Keyboard::RBracket)     ///< The ] key
        return shift ? '}': ']';
    else if(key == sf::Keyboard::Comma)        ///< The , key
        return shift ? '<': ',';
    else if(key == sf::Keyboard::Period)       ///< The . key
        return shift ? '>': '.';
    else if(key == sf::Keyboard::Quote)        ///< The ' key
        return shift ? '"': '\'';
    else if(key == sf::Keyboard::Slash)
        return '/';
    else if(key == sf::Keyboard::Equal)
        return shift ? '=': '=';
    else if(key == sf::Keyboard::Space)
        return ' ';
#if NEW_SFML_KEYS
    else if(key == sf::Keyboard::Semicolon)    ///< The ; key
        return shift ? ':': ';';
    else if(key == sf::Keyboard::Hyphen)
        return shift ? '_': '-';
    else if(key == sf::Keyboard::Enter)
        return '\n';
#else
    else if(key == sf::Keyboard::SemiColon)    ///< The ; key
        return shift ? ':': ';';
    else if(key == sf::Keyboard::Comma)
        return shift ? '_': '-';
    else if(key == sf::Keyboard::Return)
        return '\n';
#endif
    return '\0';
}

//funcao deve processar o evento alterando o estado atual e o buffer de estados.
void processKey(Ambient& amb, sf::Event& event){
    //Se o char nao for printável, retorna '\0'
    auto tecla = sf2char(event);

    if(event.key.control && (event.key.code == sf::Keyboard::Z)){ //control z
        amb.controlZ();
    }
    else if(event.key.control && (event.key.code == sf::Keyboard::R)){ //control r
        amb.controlR();
    }
    else if(tecla != '\0'){ //alguma tecla printável
        amb.insertChar(tecla);
    }
    else if(event.key.code == sf::Keyboard::BackSpace){
        amb.sendBackspace();
    }
    else if(event.key.code == sf::Keyboard::Delete){
        amb.sendDelete();
    }
    else if(event.key.code == sf::Keyboard::Left){
        amb.sendLeft();
    }
    else if(event.key.code == sf::Keyboard::Right){
        amb.sendRight();
    }
    else if(event.key.code == sf::Keyboard::Up){
        amb.sendUp();
    }
    else if(event.key.code == sf::Keyboard::Down){
        amb.sendDown();
    }
}

//########################################################
//############# FUNCOES DE DESENHO #######################
//########################################################

class sfText : public sf::Text{
    static sf::Font * get_default_font();
public:
    sfText(sf::Vector2f pos, std::string texto, sf::Color color = sf::Color::White, int size = 16);
};

sfText::sfText(sf::Vector2f pos, string texto, sf::Color color, int size){
    this->setFont(*this->get_default_font());
#if NEW_SFML_COLOR
    this->setFillColor(color);
    this->setOutlineColor(color);
#else
    this->setColor(color);
#endif
    this->setPosition(pos);
    this->setString(texto);
    this->setCharacterSize(size);
}

sf::Font *sfText::get_default_font(){
    static sf::Font font;
    static bool init = true;
    if(init){
        init = false;
#if DEFAULT_FONT
        font.loadFromMemory(font_buffer_profont, sizeof(font_buffer_profont));
#else
        if(!font.loadFromFile(font_path))
            std::cerr << "Font " << font_path << " nao encontrada." << std::endl;
#endif
    }
    return &font;
}

void draw(sf::RenderWindow& janela, string textLayer, string cursorLayer){
    static sf::Clock clock;
    static auto cursorTime = 300; //milisegundos
    static bool cursorOn = true;

    //para fazer o cursor piscar
    if(clock.getElapsedTime() > sf::milliseconds(cursorTime)){
        clock.restart();
        cursorOn = !cursorOn;
    }

    auto pos = sf::Vector2f(30, 50);
    int size = 50;
    janela.clear();
    janela.draw(sfText(pos, textLayer, sf::Color::White, size));

    if(cursorOn){
        pos.x -= size / 4.f;
        janela.draw(sfText(pos, cursorLayer, sf::Color::White, size));
    }
    janela.display();
}

string get_text_layer(string text){
    auto it = std::find(text.begin(), text.end(), '|');
    if(it == text.end()){
        cerr << "missing | on text" << endl;
        exit(1);
    }
    text.erase(it);
    return text;
}

string get_cursor_layer(string text){
    stringstream ss;
    bool found = false;
    for(auto it = text.begin(); it != text.end(); it++){
        if(*it == '|'){
            ss << "|";
            found = true;
            break;
        }
        else if(*it == '\n')
            ss << "\n";
        else
            ss << " ";
    }
    if(!found)
        ss << "|";
    return ss.str();
}

void draw_text(sf::RenderWindow& janela, string text){
    static sf::Clock clock;
    static auto cursorTime = 300; //milisegundos
    static bool cursorOn = true;

    //para fazer o cursor piscar
    if(clock.getElapsedTime() > sf::milliseconds(cursorTime)){
        clock.restart();
        cursorOn = !cursorOn;
    }

    auto pos = sf::Vector2f(30, 50);
    int size = 50;
    janela.clear();
    janela.draw(sfText(pos, get_text_layer(text), sf::Color::White, size));

    if(cursorOn){
        pos.x -= size / 4.f;
        janela.draw(sfText(pos, get_cursor_layer(text), sf::Color::White, size));
    }
    janela.display();
}
