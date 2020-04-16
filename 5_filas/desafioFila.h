#ifndef UFN_ESTRUTURAS_DESAFIOFILE_H
#define UFN_ESTRUTURAS_DESAFIOFILE_H
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// struct para a celula
typedef struct nodo {
	int dado;
	struct nodo *prox;
} Celula;

// struct para armazenar os dois ponteiros da fila
typedef struct {
	Celula *cabeca; //operacao de remocao
	Celula *cauda;  //operacao de insercao
} Fila;

void inicializacao(Fila *f);

void inserirFila(int valor, Fila *f);

int removerFila(Fila *f);

#endif
