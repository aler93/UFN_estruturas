//
// Created by Alisson Naimayer on 16/04/2020.
//

#include "desafioFila.h"

int main() {
	new();
	int prioridade, ficha = 1;
	int prioritarias = 10; // Porcentagem de fichas prioritarias geradas
	Fila normal, prioritaria;

	inicializacao(&normal);
	inicializacao(&prioritaria);

	int tamanhoFila = 120, atdP = 0, atdN = 0, nmrAtd = 0, rm;
	int i, id, chunk;

	// define duas threads para o sistema; t0 = gera ficha, t1 atende a ficha
	//omp_set_num_threads(2);
#pragma omp parallel private( nmrAtd, id ) shared( normal, prioritaria, ficha ) num_threads(2)
	{
		do {
			id = omp_get_thread_num(); // qual thread está executando?
			// Se for a t0; gera um atendimento
			if( id == 0 && tamanhoFila > 0 ) { // se remover "&& tamanhoFila > 0" vai gerar fichas indefinidamente
				prioridade = rand() % 100;
				if( prioridade > prioritarias ) {
					inserirFila(ficha, 0, &normal);
					atdN++;
				} else {
					inserirFila(ficha, 1, &prioritaria);
					atdP++;
				}
				tamanhoFila--;
				ficha++;
			}

			// Se for a t1; verifica se há fila e atende
			if( id == 1 ) {
				if( normal.cabeca ) {
					if( nmrAtd > 2 ) {
						termYellow(false);
						printf("\tDando preferência para prioritárias\n");
						if( prioritaria.cabeca ) {
							removerFila(&prioritaria);
							nmrAtd = 0;
						} else {
							termRed(false);
							printf("\tNão há fila prioritária\n");
							termDefault();
						}
					}
					removerFila(&normal);
					nmrAtd++;
				}
				if( prioritaria.cabeca ) {
					removerFila(&prioritaria);
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
void inserirFila(int valor, int prioritaria, Fila *f) {
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

	if( prioritaria == 1 ) {
		termYellow(true);
		printf("Retirada a ficha %d (prioritária) para atendimento\n", valor);
	} else {
		termDefault();
		printf("Retirada a ficha %d para atendimento\n", valor);
	}

	termDefault();
	sleep(1); // demora 1 segundo para retirar a ficha
}

/**
 * Remove elemento da cabeca da fila
 * @param f *Fila
*/
int removerFila(Fila *f) {
	sleep(2); // demora 2 segundos para atender a ficha
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

		termGreen(true);
		printf("\tA ficha %d foi atendida\n", ficha);
		termDefault();

		return ficha;
	} else {
		termRed(true);
		printf("Fila vazia\n");
		termDefault();

		return -27;
	}
}

void new() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
}
