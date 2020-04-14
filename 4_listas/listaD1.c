/**
 * @author: Alisson Naimayer (13/04/2020)
 * @Contact: anaimayer3@gmail.com
 * @Compiler: LLVM/Clang
 * @OS: Fedora 31 x86_64
 * @copyright: GPLv2
*/

#include "listaD1.h"

int main() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));

	CelulaD *lista = NULL;

	lista = inserirDupla(1, lista);
	lista = inserirDupla(2, lista);
	lista = inserirDupla(3, lista);
	lista = inserirDupla(4, lista);
	lista = inserirDupla(5, lista);

	int qnt;
	qnt = exibirDupla(lista);

	excluirDupla(1, lista);

	exibirDupla(lista);

	printf("\n");
	return 1;
}

int exibirDupla(CelulaD *lista) {
	if( !lista ) {
		printf("Lista vazia\n");

		return 0;
	}

	// retorna o ponteiro da lista pro primeiro elemento
	for( ; lista->ant; lista = lista->ant );

	CelulaD *p;
	int i = 0;

	for( p = lista; p; p = p->prox ) {
		printf("%d  |", p->conteudo);
		i++;
	}

	printf("\n");

	return i;
}

int contarDupla(CelulaD *lista) {
	if( !lista ) {
		printf("Lista vazia\n");

		return 0;
	}

	// retorna o ponteiro da lista pro primeiro elemento
	for( ; lista->ant; lista = lista->ant );

	CelulaD *p;
	int i = 0;

	for( p = lista; p; i++, p = p->prox );

	return i;
}

CelulaD *localizarDupla(int valor, CelulaD *lista) {
	if( !lista ) {
		return NULL;
	}

	for( ; lista->ant; lista = lista->ant );

	CelulaD *p;

	for( p = lista; p; p = p->prox ) {
		if( p->conteudo == valor ) {
			return p;
		}
	}

	return NULL;
}

//inserindo na lista com ordenacao. Na sua posição correta: no início, no fim, ou no meio
CelulaD *inserirDupla(int valor, CelulaD *lista) {
	CelulaD *novo;
	CelulaD *pR, *p;

	novo = (CelulaD *) malloc(sizeof(CelulaD));

	novo->conteudo = valor;
	novo->prox = NULL;
	novo->ant = NULL;

	if( !lista ) {
		return novo;
	}

	for( ; lista->ant; lista = lista->ant );

	//percorrer a lista a procura da posicao correta
	for( pR = NULL, p = lista; p; pR = p, p = p->prox ) {
		if( valor < p->conteudo ) {
			break;
		}
	}

	//numero inserido como primeiro
	if( !pR ) { // p == lista
		novo->prox = p; //ou novo->prox = lista;
		p->ant = novo;
		return novo;
	} else if( p == NULL ) {//numero inserido na ultima posicao
		pR->prox = novo;
		novo->ant = pR;
	} else {//numero inserido no meio
		pR->prox = novo;
		novo->ant = pR;
		novo->prox = p;
		p->ant = novo;
	}

	return lista; //retornamos o primeiro elemento
}

CelulaD *excluirDupla(int valor, CelulaD *lista) {
	CelulaD *p, *pR;

	if (!lista) {
		printf("Lista vazia\n");
		return lista;
	}

	for( ; lista->ant; lista = lista->ant );

	for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
		if (valor == p->conteudo) {
			printf("Valor %d localizado e será removido\n", valor);

			break;
		}
	}

	if (!p) {
		printf("Valor não localizado\n");
		return lista;
	}
	//valor é o primeiro elemento
	if (!pR) {
		//código para remover o primeiro elemento
		lista = lista->prox;
		lista->ant = NULL;
	} else if (!p->prox) {
		//código para remover o último elemento
		pR->prox = NULL;
	} else {
		//código para remover o elemento que estiver no meio da lista
		pR->prox = p->prox;
		pR->prox->ant = pR;
	}
	free(p);

	return lista;
}

CelulaD *destruirDupla(CelulaD *lista) {
	CelulaD *p, *pR;

	for( ; lista->ant; lista = lista->ant );
	for( pR = lista, p = lista->prox; p; pR = p, p = p->prox ) {
		free(pR);
	}
	free(pR);

	printf("Memória liberada\n");

	return NULL;
}
