#include <stdio.h>
#include <stdlib.h>
#include <tabuleiro.h>

typedef struct peca{ //Um vetor de peças é considerado o tabuleiro
  char tipo;  //tipo da peca (PEDRA PAPEL E TESOURA)
  int posX, posY; //posicao da peca
}peca_t;

struct tabuleiro{
  peca_t **tab; // Vetor de ponteiros de peças (Cada posição recebe um endereço de uma peça)
  int nLinhas, nColunas;
};

peca_t *create_peca(char tipo, int posX, int posY){
  peca_t *peca = (peca_t *) malloc(sizeof(peca_t ));

  peca->tipo = tipo;
  peca->posX = posX;
  peca->posY = posY;

  return peca;
}

// Tabuleiro é composto de um vetor de peças e suas dimensões
tab_t *create_tabuleiro(int nLinhas, int nColunas){
  tab_t *tabuleiro = (tab_t *) malloc(sizeof(tab_t));

  tabuleiro->tab = (peca_t **) malloc(sizeof(peca_t *) * (nLinhas * nColunas));
  tabuleiro->nLinhas = nLinhas;
  tabuleiro->nColunas = nColunas;

  return tabuleiro;
}

void insert_peca(tab_t *tabuleiro, int posX, int posY, char peca){
  peca_t *aux = create_peca(peca, posX, posY);
  tabuleiro->tab[posX * tabuleiro->nLinhas + tabuleiro->nColunas] = aux;
}

void print_tabuleiro(tab_t *my_tab){
  for (int i = 0; i < my_tab->nLinhas * my_tab->nColunas; i++){
    if(i % my_tab->nLinhas == 0) printf("\n");
    printf("%c ", my_tab->tab[i]->tipo);
  }
}

// Recebe o endereço do tabuleiro, apaga e marca como NULL
void *delete_tabuleiro(tab_t **tabuleiro){
  free(*tabuleiro);

  *tabuleiro = NULL;
}
