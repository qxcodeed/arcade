#define XPAINT
#include "xpaint.h"
#include <vector>
#include <iostream>


void square (float x, float y, float lado){
    //x_color_set(rand() % 256, rand() % 256, rand() % 256, 255);

    x_pen_set_pos(x, y);
    x_pen_set_angle(0);
    x_pen_walk(lado);
    x_pen_rotate(-90);
    x_pen_walk(lado);
    x_pen_rotate(-90);
    x_pen_walk(lado);
    x_pen_rotate(-90);
    x_pen_walk(lado);
}

void quadrados(int x, int y, float lado){
    square(x, y, lado);
    if(lado < 10)
        return;
    float tam = lado * 0.46;
    quadrados(x - tam/2, y - tam/2, tam);
    quadrados(x + lado - tam/2, y - tam/2, tam);
    quadrados(x - tam/2, y + lado - tam/2, tam);
    quadrados(x + lado - tam/2, y + lado  - tam/2, tam);
}


int main() {
    x_open(854, 480, "img_quadrados");
    quadrados(300, 125, 250);
    x_save();
    x_close();
}