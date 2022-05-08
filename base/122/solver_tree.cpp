#define XPAINT
#include "xpaint.h"
#include <iostream>

void draw_tree(double size) {
    if (size < 1)
        return;
    int angle = x_math_rand(25, 45);
    double fator = x_math_rand(65, 80)/100.0;
    x_pen_set_thick((int) size/40 + 1);
    auto r255 = [](){ return x_math_rand(0, 256);};
    x_color_set(r255(), r255(), r255());
    x_pen_walk(size);
    x_pen_rotate(-angle);
    draw_tree(size * fator);
    x_pen_rotate(2 * angle);
    draw_tree(size * fator);
    x_pen_rotate(-angle);
    x_pen_walk(-size);
}

int main() {
    x_open(600, 500, "img_tree");
    x_pen_set_angle(90);
    x_pen_set_pos(300, 490);
    draw_tree(130);
    x_save();
    x_close();
}