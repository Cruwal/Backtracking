#include<stdio.h>


int verifica(int** todasCedulas, int nCedulas, int nLinhas, int nColunas){//1 Sucesso
	int count, i, j, aux;
	char verificada[nLinhas][nColunas];
	for(i = 0; i < nLinhas; i++)
		for(j = 0; j < nColunas; j++)
			verificada[i][j] = 0;
	if(todasCedulas == NULL)
		return -1;

	if(nCedulas == 1)
		return 1;
	else{//Se a quantidade de cedulas no tabuleiro for maior que 1 eh verificado ilha
		for(i = 0; i < nLinhas; i++){
			count = 0;
			for(j = 0; j < nColunas; j++){
				if(todasCedulas[i][j] != 0 && verificada[i][j] != 1){//Se eh uma cedula nao vazia e nao foi verificada
					aux = count;
					count = count + (j+1 < nColunas && todasCedulas[i][j+1] == 0);
					if(aux+1 == count)
						verificada[i][j+1] = 1;

					aux = count;
					count = count + (j-1 >=0  && todasCedulas[i][j-1] == 0);
					if(aux+1 == count)
						verificada[i][j-1] = 1;

					aux = count;
					count = count + (i+1 < nLinhas && todasCedulas[i+1][j] == 0);
					if(aux + 1 == count)
						verificada[i+1][j] = 1;

					aux = count;
					count = count +  (i-1 >= 0 && todasCedulas[i-1][j] == 0);//Contabiliza com relacao a cedulas
					if(aux+1 == count)
						verificada[i-1][j] = 1;

					count = count + (j+1 == nColunas) + (j-1 < 0) + (i+1 == nLinhas) + (i-1 < 0);//Se nao for possivel verificar pois a cedula se encontra na borda entao contabiliza ele
					
					if(count == 4 ) return 1;//
					else count = 0; //Zera pra proxima verificacao
				}
			}
		}
	}
	return 0;
}
