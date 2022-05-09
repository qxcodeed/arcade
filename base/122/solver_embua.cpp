#define XPAINT
#include "xpaint.h"

void draw_line(int size) {
    if (size < 10)
        return;
    x_pen_walk(size);
    x_pen_rotate(-90);
    draw_line(size - 5);
}

int main() {
    x_open(854, 480, "img_embua");
    x_pen_set_thick(3);
    x_pen_set_angle(90);
    x_pen_set_pos(200, 460);
    draw_line(450);
    x_save();
    x_close();
}