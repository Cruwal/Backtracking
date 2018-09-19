#ifndef _LIST_H_  //NÃO PODE ESQUECER DESSES DEFINES!!!!
#define _LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct list list_t;
int put(list_t* user, int linha, int coluna, int cedula);
list_t* start_List();
void free_Function(list_t* f);
void printf_List(list_t* lista);
void printf_Saida(list_t* user);

#endif