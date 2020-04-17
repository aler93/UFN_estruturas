#ifndef UFN_ESTRUTURAS_DESAFIOFILE_H
#define UFN_ESTRUTURAS_DESAFIOFILE_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<locale.h>
#include<unistd.h>
#include<omp.h>

#include "terminalColor.c"

// struct para a celula
typedef struct nodo {
	int numFicha;
	struct nodo *prox;
} Celula;

// struct para armazenar os dois ponteiros da fila
typedef struct {
	Celula *cabeca;
	Celula *cauda;
} Fila;

void inicializacao(Fila *f);
void inserirFila(int valor, Fila *f);

void new();

int removerFila(Fila *f);

#endif
