//
// Created by aler on 13/04/2020.
//

#ifndef UFN_ESTRUTURAS_LISTAD1_H
#define UFN_ESTRUTURAS_LISTAD1_H

#endif //UFN_ESTRUTURAS_LISTAD1_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct nodo {
	int conteudo;
	struct nodo *ant;
	struct nodo *prox;
} CelulaD;

int contarDupla(CelulaD *lista);
int exibirDupla(CelulaD *lista);
CelulaD *localizarDupla(int valor, CelulaD *lista);
CelulaD *inserirDupla(int valor, CelulaD *lista);
CelulaD *excluirDupla(int valor, CelulaD *lista);
CelulaD *destruirDupla(CelulaD *lista);
