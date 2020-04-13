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

//Celula serve tanto para lista simples quanto para lista circular
typedef struct nodo {
	int conteudo;
	struct nodo *ant;
	struct nodo *prox;
} CelulaD;
