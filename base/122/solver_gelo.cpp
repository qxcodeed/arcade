#define XPAINT
#include "xpaint.h"
#include <vector>
#include <iostream>


void draw(float x, float y, double raio) {
    if (raio < 1)
        return;
    int partes = 5;
    double fator = 0.39;

    double angle = 360.0 / partes;
    for (int i = 0; i < partes; i++) {
        double xn = x + raio * x_math_cos(i * angle);
        double yn = y - raio * x_math_sin(i * angle);
        x_fill_line(x, y, xn, yn, raio / 60 + 1);
        draw(xn, yn, raio * fator);
    }
}

int main() {
    x_open(1200, 1200, "img_gelo");
    draw(600, 600, 350);
    x_save();
    x_close();
}