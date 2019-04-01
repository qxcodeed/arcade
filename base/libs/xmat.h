#define H_ONLY //importante para não dar problema do include na main
#include "xpaint.h"

int MAT_SIDE = 35;
int MAT_DELTA = 0;
static int MAT_NL = 0;
static int MAT_NC = 0;


void xmat_init(int nl, int nc){
    int side = MAT_SIDE;
    x_open(side * (nc + 2), side * (nl + 2));
    MAT_NL = nl;
    MAT_NC = nc;
/*  
    float prop_image = xg_width()/(float)xg_height();
    
    float prop_mat = nc/(float)nl;

    if(prop_image < prop_mat)
        MAT_SIDE = xg_width() / (float)(nc + 2);
    else
        MAT_SIDE = xg_height() / (float)(nl + 2); */
}

void xmat_put_square(int l, int c, XColor color){
    xs_color(color);
    xd_filled_rect((c + 1) * MAT_SIDE + MAT_DELTA, (l + 1) * MAT_SIDE + MAT_DELTA, 
                   (c + 2) * MAT_SIDE - MAT_DELTA, (l + 2) * MAT_SIDE - MAT_DELTA);
}

void xmat_put_circle(int l, int c, XColor color){
    xs_color(color);
    xd_filled_circle((c + 1) * MAT_SIDE + MAT_SIDE/2, (l + 1) * MAT_SIDE + MAT_SIDE/2, 
                   MAT_SIDE/2 - MAT_DELTA);
}

void xmat_put_number(int l, int c, XColor color, int value){
    xs_color(color);
    if(value < 10){
        xs_font_size(MAT_SIDE * 0.9);   
        x_write((c + 1.3) * MAT_SIDE, (l + 1.1) * MAT_SIDE, "%d", value);
    }else if(value < 100){
        xs_font_size(MAT_SIDE * 0.7);   
        x_write((c + 1.2) * MAT_SIDE, (l + 1.2) * MAT_SIDE, "%d", value);
    }else if(value < 1000){
        xs_font_size(MAT_SIDE * 0.5);   
        x_write((c + 1.18) * MAT_SIDE, (l + 1.3) * MAT_SIDE, "%d", value);
    }else if(value < 10000){
        xs_font_size(MAT_SIDE * 0.4);   
        x_write((c + 1.13) * MAT_SIDE, (l + 1.35) * MAT_SIDE, "%d", value);
    }else if(value < 100000){
        xs_font_size(MAT_SIDE * 0.35);   
        x_write((c + 1.10) * MAT_SIDE, (l + 1.35) * MAT_SIDE, "%d", value);
    }
}

void xmat_draw(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++)
        for(int c = 0; c < nc; c++)
            xmat_put_square(l, c, xg_palette(mat[l][c])); 
}