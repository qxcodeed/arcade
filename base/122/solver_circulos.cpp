#define XPAINT
#include "xpaint.h"
#include <vector>
#include <iostream>


void draw(float x, float y, double raio) {
    if (raio < 1)
        return;
    int partes = 5;
    double fator = 0.39;
    std::cout << raio << '\n';
    x_draw_circle(x, y, raio);

    double angle = 360.0 / partes;
    for (int i = 0; i < partes; i++) {
        draw(x + raio * x_math_cos(i * angle), 
             y - raio * x_math_sin(i * angle), 
             raio * fator);
    }
}

int main() {
    x_open(1200, 1200, "img_circulos");
    draw(600, 600, 350);
    x_save();
    x_close();
}