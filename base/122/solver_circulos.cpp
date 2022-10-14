#define XPAINT
#include "xpaint.h"
#include <vector>
#include <iostream>


void draw(float x, float y, double raio) {
    if (raio < 2)
        return;
    int partes = 5;
    double fator = 0.39;
    x_draw_circle(x, y, raio);

    double piece = 360.0 / partes;
    for (int i = 0; i < partes; i++) {
        auto angle = i * piece + 18;
        draw(x + raio * x_math_cos(angle), 
             y - raio * x_math_sin(angle), 
             raio * fator);
    }
}

int potencia (int a, int b) {
    int acc = 1; //só crie quando for necessário
    for (int i = 0; i < b; i++)
        acc *= a;
    return acc;
}

int main() {
    x_open(854, 480, "img_circulos");
    draw(427, 260, 160);
    x_save();
    x_close();
}