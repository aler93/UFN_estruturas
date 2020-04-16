//
// Created by aler on 16/04/2020.
//

#include "desafioFila.h"

int main(){
	return 1;
}

/**
 * Inicializa a fila
 * @param *f Ponteiro para a fila
*/
void inicializacao(Fila *f) {
	f->cabeca = NULL;
	f->cauda = NULL;
}

/**
 * Insere elemento na fila
 * @param valor int para ser inserido
 * @param f *Fila
*/
void inserirFila(int valor, Fila *f) {
	Celula *novo;

	novo = (Celula *) malloc(sizeof(Celula));
	novo->dado = valor;
	novo->prox = NULL;

	//eh a primeira vez?
	if( !f->cauda ) {
		f->cauda = novo;
		f->cabeca = novo;
	} else {
		f->cauda->prox = novo;
		f->cauda = novo;
	}
}

/**
 * Remove elemento da cabeca da fila
 * @param f *Fila
*/
int removerFila(Fila *f) {
	Celula *lixo;
	int ficha;
	//fila existe?
	if( f->cabeca ) {
		ficha = f->cabeca->dado;
		lixo = f->cabeca;
		f->cabeca = f->cabeca->prox;
		free(lixo);

		//caso apague o ultimo elemento
		if( !f->cabeca ) {
			f->cauda = NULL;
		}

		return ficha;
	} else {
		printf("Fila vazia\n");

		return -27;
	}
}
