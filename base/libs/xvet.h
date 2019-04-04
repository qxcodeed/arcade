#define H_ONLY
#include "xpaint.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

static float bar_width = 20; //bar width
static float yfactor = 1; //multiplicative factor of bar height
static int begin_partition = 0;
static int end_partition = 0;
static int pivot_value = 0;


void xd_vet(int * vet, int size, char * colors, ...);
void _xd_vet_and_save(int * vet, int qtd, int * indices, const char * colors);
void _xd_vet_all(int * vet, int size, int * indices, const char * colors);
void _xd_vet_i(int * vet, int size, int i);
void _xd_vet_all(int * vet, int size, int * indices, const char * colors);

void xs_partition(int begin, int end){
    begin_partition = begin;
    end_partition = end;
}

void xs_pivot(int value){
    pivot_value = value;
}

void calc_bar_width(int vet_size){
    bar_width = xg_width() / (vet_size + 2);
}

void calc_yfactor(int * vet, int size){
    int max = 0;
    for(int i = 0; i < size; i++)
        if(vet[i] > max)
            max = vet[i];
    yfactor = (xg_height() - 4.0 * bar_width);
    yfactor = yfactor < 0 ? -yfactor : yfactor;
    yfactor /= max;
    if(yfactor < 0.2)
        yfactor = 0.2;
    //printf("yf %f", yfactor);
}

//processa cores e parametros
void xd_vet(int * vet, int size, char * colors, ...){
    calc_bar_width(size);
    calc_yfactor(vet, size);
    
    int qtd_ind = 0;
    if(colors != NULL)
        qtd_ind = strlen(colors);
    if(qtd_ind == 0)
        _xd_vet_and_save(vet, size, NULL, NULL);
    else{
        int * vet_ind = malloc(qtd_ind * sizeof(int)); /* cria um vetor de inteiros na heap */
        va_list va; /* inicia a variavel que vai guardar os parametro de ... */
        va_start(va, colors); /* define a variavel que precede ... */
        int i = 0;
        for(;i < qtd_ind; i++)
            vet_ind[i] = va_arg(va, int); /* vai puxando inteiros dos parametros de ... */
        va_end(va); /* finaliza a lista variadica */
        _xd_vet_and_save(vet, size, vet_ind, colors);
        free(vet_ind); /* libera memoria */
    }
}

void _xd_partition(){
/*     if(begin_partition + 1 >= end_partition)
        return; */
    xs_color(YELLOW);
    xd_filled_rect(bar_width * (1 + begin_partition), xg_height() - (bar_width * 3/4), 
                   bar_width * (2 + end_partition) , xg_height()- (bar_width * 1/4));
}

void _xd_pivot(int size){
/*     if(begin_partition + 1 >= end_partition)
        return; */
    xs_color(RED);
    xd_line(bar_width, xg_height() - bar_width - pivot_value * yfactor, 
            (1 + size) * bar_width, xg_height() - bar_width - pivot_value * yfactor);
}

//limpa, pinta, salva
void _xd_vet_and_save(int * vet, int size, int * indices, const char * colors){
    static int atual = 0;
    x_clear(BLACK);
    _xd_vet_all(vet, size, indices, colors);
    _xd_partition();
    _xd_pivot(size);
//    printf("%d\n", atual);
    x_write(0, 0, "%d", atual++);
    x_step("sort");
}

void _xd_vet_i(int * vet, int size, int i){
    if((i < 0)||(i >= size))
        return;
    int x = bar_width * (i + 1);
    int ybase = xg_height() - bar_width;
    int j;
    for(j = 0; j < ((int) bar_width - 2) ; j++)
        xd_line(x + j, ybase, x + j, ybase - yfactor * vet[i]);
}

void _xd_vet_all(int * vet, int size, int * indices, const char * colors){
    int i = 0;
    xs_color(WHITE);
    for(i = 0; i < size; i++)
        _xd_vet_i(vet, size, i);

    if(colors == NULL)
        return;
    int qtd_indices = strlen(colors);
    int j = 0;
    for(j = 0; j < qtd_indices; j++){
        i = indices[j];
        xs_color(xg_palette(colors[j]));
        _xd_vet_i(vet, size, i);
    }
}
