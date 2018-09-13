#ifndef _TABULEIRO_H_
#define _TABULEIRO_H_

typedef struct tabuleiro tab_t;

tab_t *create_tabuleiro(int nLinhas, int nColunas);
void insert_peca(tab_t *tabuleiro, int posX, int posY, char peca);
void print_tabuleiro(tab_t *tabuleiro);
void *delete_tabuleiro(tab_t **tabuleiro);

#endif
