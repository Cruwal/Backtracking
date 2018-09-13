#include <stdio.h>
#include <list.h>
#include <tabuleiro.h>

int main( int argc, char* argv [] ) {
	int linha, coluna;
	tab_t *tabuleiro = NULL;
	// list_t* user;
	// user = start_List();

	printf("Digite numero de linhas e colunas: ");
	scanf("%d %d", &linha, &coluna);
	tabuleiro = create_tabuleiro(linha, coluna);

	for(int i = 0; i < linha; i++)
		for(int j = 0; j< coluna; j++)
			insert_peca(tabuleiro, i, j, 'A' + i + j);

	print_tabuleiro(tabuleiro);

	//Passando o endereço do tabuleiro para apagá-lo
	delete_tabuleiro(&tabuleiro);
	// printf("Tabuleiro: %p\n", tabuleiro);
	return 0;
}
