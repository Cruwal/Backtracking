#include <stdio.h>
#include <stdlib.h>
#include <tabuleiro.h>

typedef struct peca{ //Um vetor de peças é considerado o tabuleiro
  char tipo;  //tipo da peca (PEDRA PAPEL E TESOURA)
  int posX, posY; //posicao da peca
}peca_t;

struct tabuleiro{
  peca_t *tab;
  int nLinhas, nColunas;
};

peca_t *create_peca(char tipo, int posX, int posY){
  peca_t *peca = (peca_t *) malloc(sizeof(peca_t));

  peca->tipo = tipo;
  peca->posX = posX;
  peca->posY = posY;

  return peca;
}

tab_t *create_tabuleiro(int nLinhas, int nColunas){
  tab_t *tabuleiro = (tab_t *) malloc(sizeof(tab_t));

  tabuleiro->tab = (peca_t *) malloc(sizeof(peca_t) * (nLinhas * nColunas));
  tabuleiro->nLinhas = nLinhas;
  tabuleiro->nColunas = nColunas;

  return tabuleiro;
}

void insert_peca(tab_t *tabuleiro, int posX, int posY, char peca){}

void print_tabuleiro(tab_t *tabuleiro){}

// Recebe o endereço do tabuleiro, apaga e marca como NULL
void *delete_tabuleiro(tab_t **tabuleiro){
  free(*tabuleiro);

  *tabuleiro = NULL;
}
