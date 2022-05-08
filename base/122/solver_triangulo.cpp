#define XPAINT
#include "xpaint.h"
#include <vector>
#include <iostream>


void draw(double tam) {
    if (tam < 4)
        return;
    for(int i = 0; i < 3; i++){
        x_pen_walk(tam);
        x_pen_rotate(120);
        draw(tam / 2);
    }
}

int main() {
    x_open(1100, 1100, "img_triangulo");
    x_pen_set_angle(0);
    x_pen_set_pos(50, 1000);
    draw(1000);
    x_save();
    x_close();
}