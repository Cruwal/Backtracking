#include <list.h>

typedef struct no no_t;
struct no{
	int repeticoes;//Informa o numero de maneiras diferentes para chegar um unico resultado
	int linha;
	int coluna;
	int cedula;
	no_t* prox;
};


struct list{
	int number;//Informa quantos NO's(Estados finais distintos) existe na fila
	no_t* inicio;
	no_t* fim;
};

int isEmpty(list_t* user){
	if(user == NULL)
		return -1;
	return (user->inicio == NULL);
}

no_t* create_Node(int linha, int coluna, int cedula){
	no_t* new = NULL;
	new = (no_t*)malloc(sizeof(no_t));
	new->linha = linha;
	new->coluna = coluna;
	new->cedula = cedula;
	new->repeticoes = 1;
	new->prox = NULL;
	return new;
}

int put(list_t* user, int linha, int coluna, int cedula){
	no_t* new;
	no_t* ant, * atual;
	if(user == NULL) return -1;
	if(user->inicio == NULL){
 		new = create_Node( linha, coluna, cedula);
		user->inicio = new;
		user->fim = new;
		user->number++;//Informa que foi incluido um NO(estado final distinto) na fila
	}else{
		ant = NULL;
		atual = user->inicio;
		//Verifica se esse resultado ja existe registrado
		while(atual != NULL && atual->linha < linha){//Ordenando por linha
			ant = atual;
			atual = atual->prox;
		}
		if(atual != NULL && atual->linha == linha){
			while(atual != NULL && atual->coluna < coluna){//Desempate por coluna
				ant = atual;
				atual = atual->prox;
			}
			if(atual->coluna == coluna){
				while(atual != NULL && atual->cedula < cedula){//Desempate por cedula
					ant = atual;
					atual = atual->prox;
				}
			}
		}

		if(atual == NULL){/*Atual chegou no fim, significa que nao houve nenhum NO igual*/
			new = create_Node( linha, coluna, cedula);
			ant->prox = new;
			user->fim = new;
			user->number++;//Informa que foi incluido mais um NO(estado final distinto) na fila
		}else if(atual->linha == linha && atual->coluna == coluna && atual->cedula == cedula){//Mesmo resultado com caminho diferente
			atual->repeticoes++;
		}else if(ant == NULL){
			new = create_Node( linha, coluna, cedula);
			new->prox = user->inicio;
			user->inicio = new;
			user->number++;
		}else{//Nesse caso estara entre dois NO's o resultado
			new = create_Node( linha, coluna, cedula);
			ant->prox = new;
			new->prox = atual;
			user->number++;
		}
	}
	return 1;
}

list_t* start_List(){
	list_t* user = NULL;
	user = (list_t*)malloc(sizeof(list_t));
	user->inicio = NULL;
	user->fim = NULL;
	user->number = 0;
	return user;
}

void printf_List(list_t* lista){
	no_t* ant = lista->inicio;

	while(ant != NULL){
		printf("Cedula: %d, Linha: %d, Coluna: %d\n", ant->cedula, ant->linha, ant->coluna);
		ant = ant->prox;
	}
	printf("\n");
}


void printf_Saida(list_t* user){
	
}

void free_Function(list_t* f){
	no_t* aux;
	if(f == NULL) return;
	aux = f->inicio;
	while(aux != NULL){
		f->inicio = f->inicio->prox;
		free(aux);
		aux = f->inicio;
	}
	free(f);
}