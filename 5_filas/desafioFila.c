//
// Created by aler on 16/04/2020.
//

#include "desafioFila.h"

int main() {
	new();
	Fila fila;
	inicializacao(&fila);

	for( int i = 1; i < 31; i++ ) {
		inserirFila(i, &fila);
	}

	atender(31, &fila);

	return 1;
}

void atender(int qnt, Fila *f) {
	int normal = 0, prioridade = 0;

	for( int i = 1; i < qnt; i++ ) {
		if( f->cabeca->prioridade == 1 ) {
			prioridade++;
			termYellow(true);
		} else {
			normal++;
			termDefault();
		}
		printf("Ficha atendida: %d", f->cabeca->numFicha);
		if( f->cabeca->prioridade == 1 ) {
			printf(" (prioritária)");
		}
		printf("\n");
		removerFila(f);
	}
	termMagenta(false);
	printf("Fichas normais: %d  |  Fichas prioritárias: %d\n", normal, prioridade);
	termDefault();
}

/**
 * fichasPrioritarias - Define uma % de fichas prioritarias que serão geradas
 * @param *f Ponteiro para a fila
*/
void fichasPrioritarias(int porcentagem) {
	if( porcentagem < 0 ) {
		printf("A porcentagem não pode ser menor que 0\n");
		porcentagem = 0;
	}
	if( porcentagem > 100 ) {
		printf("A porcentagem não pode ser maior que 100\n");
		porcentagem = 100;
	}

	prioritarias = porcentagem;
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
	int prioridade;

	novo = (Celula *) malloc(sizeof(Celula));
	novo->numFicha = valor;
	prioridade = rand() % 100;

	if( prioridade < prioritarias ) {
		termRed(true);
		novo->prioridade = 1;
	} else {
		termBlue(true);
		novo->prioridade = 0;
	}
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

	if( f->cabeca ) {
		ficha = f->cabeca->numFicha;
		lixo = f->cabeca;
		f->cabeca = f->cabeca->prox;
		free(lixo);

		if( !f->cabeca ) {
			f->cauda = NULL;
		}

		return ficha;
	} else {
		termRed(true);
		printf("Fila vazia\n");

		return -27;
	}
}

void new() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	fichasPrioritarias(30); // 30% de chance de uma ficha ser prioritária
}
