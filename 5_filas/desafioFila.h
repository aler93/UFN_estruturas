#ifndef UFN_ESTRUTURAS_DESAFIOFILE_H
#define UFN_ESTRUTURAS_DESAFIOFILE_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<locale.h>

#include "terminalColor.c"

// struct para a celula
typedef struct nodo {
	int numFicha;
	int prioridade;
	struct nodo *prox;
} Celula;

// struct para armazenar os dois ponteiros da fila
typedef struct {
	Celula *cabeca;
	Celula *cauda;
} Fila;

int prioritarias = 50; // Porcentagem de fichas prioritarias geradas

void inicializacao(Fila *f);
void inserirFila(int valor, Fila *f);
void fichasPrioritarias(int porcentagem);
void new();
void atender(int qnt, Fila *f);

int removerFila(Fila *f);

#endif
