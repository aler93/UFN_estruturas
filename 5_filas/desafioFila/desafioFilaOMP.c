//
// Created by Alisson Naimayer on 16/04/2020.
//

#include "desafioFilaOMP.h"

int main() {
	new();

	int prioritarias = 33; // Porcentagem de fichas prioritarias geradas
	int tamanhoFila = 100;

	int prioridade, ficha = 1;
	Fila normal, prioritaria;

	int tempoAtender = 3, tempoGerar = 1;

	inicializacao(&normal);
	inicializacao(&prioritaria);

	int atdP = 0, atdN = 0, nmrAtd = 0, rm;
	int i, id, chunk;

	// define quatro threads para o sistema;
	// t0 "recepcionista" = Gera fichas para serem atendidas;
	// t1 e t2 "Atendimento", atende a fila normal, e a cada três atendimentos ajuda com a fila prioritária;
	// t3 "Atedimento prioritário" atende a fila prioritária, se esta estiver vazia, ajuda com a fila normal;
#pragma omp parallel private( nmrAtd, id ) shared( normal, prioritaria, ficha ) num_threads(4)
	{
		do {
			id = omp_get_thread_num();

			// Recepcionista
			if( id == 0 && tamanhoFila > 0 ) {
				prioridade = rand() % 100; // nível de prioridade
				if( prioridade > prioritarias ) {
					termGreen(false);
					printf("t%d: Gerada a ficha %d (normal) para atendimento\n", id, ficha);
					termDefault();

					inserirFila(ficha, &normal);
					sleep(tempoGerar);
					atdN++;
				} else {
					termYellow(false);
					printf("t%d: Gerada a ficha %d (prioritária) para atendimento\n", id, ficha);
					termDefault();

					inserirFila(ficha, &prioritaria);
					sleep(tempoGerar);
					atdP++;
				}
				tamanhoFila--;
				ficha++;
			}
			termDefault();

			// Atendimento normal
			if( id == 1 || id == 2 ) {
				if( normal.cabeca ) {
					if( nmrAtd > 2 ) {
						if( prioritaria.cabeca ) {
							printf("\tt%d: Dando preferência para ficha %d (prioritária)\n", id, prioritaria.cabeca->numFicha);
							removerFila(&prioritaria);
							sleep(tempoAtender);
						} else {
							printf("\tt%d: Não há fila prioritária. Resumindo atendimento\n", id);
							nmrAtd = 0;
						}

						nmrAtd = 0;
					} else {
						printf("\tt%d: A ficha %d foi atendida\n", id, normal.cabeca->numFicha);
						removerFila(&normal);
						sleep(tempoAtender);

						nmrAtd++;
					}
				} else if( prioritaria.cabeca ) { // se não houver atendimentos normais, ajuda com a fila de prioritários
					printf("\tt%d: Não há atendimentos normais, ajudando com prioritários\n", id);

					printf("\tt%d: A ficha %d foi atendida\n", id, prioritaria.cabeca->numFicha);
					removerFila(&prioritaria);
					sleep(tempoAtender);
				} else {
					printf("\tt%d: Nada para fazer #coffeebreak\n", id);
					sleep(1);
				}
			}

			// Atendimento prioritário
			if( id == 3 ) {
				sleep(tempoAtender);
				if( prioritaria.cabeca ) {
					printf("\tt%d: A ficha %d foi atendida\n", id, prioritaria.cabeca->numFicha);
					removerFila(&prioritaria);
					sleep(tempoAtender);
				} else if( normal.cabeca ) { // se não hourver prioritários, ajuda com a fila normal
					printf("\tt%d: Não há atendimentos prioritários, ajudando com normais\n", id);

					printf("\tt%d: A ficha %d foi atendida\n", id, normal.cabeca->numFicha);
					removerFila(&normal);
					sleep(tempoAtender);
				} else {
					printf("\tt%d: Nada para fazer #coffeebreak\n", id);
					sleep(1);
				}
			}
		} while( tamanhoFila > 0 || normal.cabeca || prioritaria.cabeca );
	}

	termMagenta(true);
	printf("\nForam geradas %d fichas normais e %d prioritárias\n\n", atdN, atdP);

	termDefault();

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
	novo->numFicha = valor;

	novo->prox = NULL;

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

		//termGreen(true);
		//printf("\tA ficha %d foi atendida\n", ficha);
		termDefault();

		return ficha;
	} else {
		termRed(true);
		printf("\tFila vazia!\n");
		termDefault();

		return -27;
	}
}

void new() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
}
