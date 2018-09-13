#include <stdio.h>
#include <stdlib.h>
#include <tabuleiro.h>

struct peca{ //Um vetor de peças é considerado o tabuleiro
  char tipo;  //tipo da peca (PEDRA PAPEL E TESOURA)
  int x, y; //posicao da peca
};

peca_t *create_tabuleiro(int nLinhas, int nColunas){
  peca_t *tabuleiro = (peca_t *) malloc(sizeof(peca_t) * (nlinhas * nColunas));

  return tabuleiro;
}

void insert_peca(peca_t *tabuleiro, int posX, int posY){
  
}
