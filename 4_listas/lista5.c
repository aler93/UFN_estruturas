#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

//inserindo na lista com ordenacao. Na sua posição correta: no início, no fim, ou no meio
Celula *inserir(int valor, Celula *lista) {
	Celula *novo; //para alocar nova celula
	Celula *p, *pR;

	//alocar memoria
	novo = (Celula *) malloc(sizeof(Celula));
	//depositar valor
	novo->conteudo = valor;
	novo->prox = NULL; //nao sabemos onde o novo será inserido

	//percorrer a lista a procura da posicao correta
	for( pR = NULL, p = lista; p; pR = p, p = p->prox ) {
		if( valor < p->conteudo ) {
			//achamos a posicao
			break;
		}
	}
	//numero inserido como primeiro
	if( !pR ) { // p == lista
		novo->prox = p; //ou novo->prox = lista;
		return novo;
	} else if( p == NULL ) {//numero inserido na ultima posicao
		pR->prox = novo;
	} else {//numero inserido no meio
		pR->prox = novo;
		novo->prox = p;
	}
	return lista; //retornamos o primeiro elemento
}

void exibir(Celula *lista) {
	Celula *p;
	if( !lista ) {
		printf("Lista vazia.\n");

		return;
	}
	for( p = lista; p; p = p->prox ) {
		printf("%d\t", p->conteudo);
	}
	printf("\n");
}

int contar(Celula *lista) {
	Celula *p;
	int total = 0;
	for( p = lista; p; p = p->prox, total++ );

	return total;
}

Celula *popular(Celula *lista, int quantidade) {
	int i;
	for( i = 0; i < quantidade; i++ ) {
		lista = inserir(( 60 + rand() % 300 ), lista);
	}
	return lista;
}

Celula *mesclar(Celula *lista1, Celula *lista2) {
	Celula *listaResultado = NULL;
	Celula *p;

	for( p = lista1; p; p = p->prox ) {
		listaResultado = inserir(p->conteudo, listaResultado);
	}

	for( p = lista2; p; p = p->prox ) {
		listaResultado = inserir(p->conteudo, listaResultado);
	}

	return listaResultado;
}

Celula *localizar(int valor, Celula *topo) {
	Celula *p;
	if( topo ) {
		for( p = topo; p; p = p->prox ) {
			if( valor == p->conteudo ) {
				return p;
			}
		}
	}
	return NULL;
}

Celula *mesclarSemDuplicidade(Celula *lista1, Celula *lista2) {
	Celula *listaResultado = NULL;
	Celula *p;

	// Insere todos os valores da lista1
	for( p = lista1; p; p = p->prox ) {
		listaResultado = inserir(p->conteudo, listaResultado);
	}

	for( p = lista2; p; p = p->prox ) {
		if( !localizar(p->conteudo, listaResultado)) {
//			^ se não localizar p->conteudo insere o valor	
			listaResultado = inserir(p->conteudo, listaResultado);
		}
	}

	return listaResultado;
}

Celula *remover(Celula *lista) {
	Celula *lixo;

	if( !lista ) {
		printf("Lista vazia\n");
		return lista;
	}

	lixo = lista;
	lista = lista->prox;

	return lista;
}

Celula *destruirLista(Celula *lista) {
	Celula *p, *pR;

	for( pR = lista, p = lista->prox; p; pR = p, p = p->prox ) {
		free(pR);
	}
	free(pR);

	return NULL;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	/*Celula *lista1 = NULL;
	lista1 = popular(lista1, 10);
	printf("A lista1 contém: %d números sorteados\n", contar(lista1));
	exibir(lista1);*/

	Celula *lista2 = NULL;
	lista2 = popular(lista2, 100);
	printf("A lista2 contém: %d números sorteados\n", contar(lista2));
	exibir(lista2);

	printf("\n");

	/*Celula *lista3 = NULL;
	lista3 = mesclar(lista1, lista2);
	printf("A lista3 contém: %d números mesclados das 2 primeiras listas\n", contar(lista3));
	exibir(lista3);

	Celula *lista4 = NULL;
	lista4 = mesclarSemDuplicidade(lista1, lista2);
	printf("A lista4 contém: %d números mesclados, sem duplicidade\n", contar(lista4));
	exibir(lista4);*/

	// Liberando RAM da lista 2
	lista2 = destruirLista(lista2);

	printf("A lista2 contém: %d números\n", contar(lista2));
	exibir(lista2);

	return 1;
}
