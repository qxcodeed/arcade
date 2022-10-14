#define XPAINT
#include "xpaint.h"
#include <iostream>

void draw(double size) {
    if (size < 5)
        return;
    double fator = 0.37;
    double angle = 42;
    for (int i = 0; i < 4; i++) {
        x_pen_walk(size / 4.0);
        x_pen_rotate(-angle);
        draw(size * fator);
        x_pen_rotate(2 * angle);
        draw(size * fator);
        x_pen_rotate(-angle);
    }
    x_pen_up();
    x_pen_walk(-size);
    x_pen_down();
}

int main() {
    x_open(1000, 1000, "img_trigo");
    x_pen_set_angle(90);
    x_pen_set_pos(500, 990);
    draw(500);
    x_save();
    x_close();
}