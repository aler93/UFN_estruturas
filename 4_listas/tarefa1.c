/**
 * Developer Alisson M. Naimayer
 * Compiler: LLVM Clang
 * OS: Fedora 31 64 bits
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

Celula *removerFaixa(int menor, int maior, Celula *lista);
Celula *excluir(int valor, Celula *lista);
Celula *localizar(int valor, Celula *topo);
Celula *popular(Celula *lista, int quantidade);
int contar(Celula *lista);
void exibir(Celula *lista);
Celula *inserir(int valor, Celula *lista);

typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	Celula *lista = NULL;
	lista = popular(lista, 10);
	exibir(lista);

	lista = removerFaixa(2, 6, lista);
	exibir(lista);

	return 1;
}

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
	for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
		if (valor < p->conteudo) {
			//achamos a posicao
			break;
		}
	}
	//numero inserido como primeiro
	if (!pR) { // p == lista
		novo->prox = p; //ou novo->prox = lista;
		return novo;
	} else if (p == NULL) {//numero inserido na ultima posicao
		pR->prox = novo;
	} else {//numero inserido no meio
		pR->prox = novo;
		novo->prox = p;
	}
	return lista; //retornamos o primeiro elemento
}

void exibir(Celula *lista) {
	Celula *p;
	if (!lista) {
		printf("Lista vazia.\n");
		return;
	}
	for (p = lista; p; p = p->prox) {
		printf("%d\t", p->conteudo);
	}
	printf("\n");
}

int contar(Celula *lista) {
	Celula *p;
	int total = 0;
	for (p = lista; p; p = p->prox, total++);

	return total;
}

Celula *popular(Celula *lista, int quantidade) {
	int i;
	for (i = 0; i < quantidade; i++) {
		lista = inserir((60 + rand() % 300), lista);
	}
	return lista;
}

Celula *localizar(int valor, Celula *topo) {
	Celula *p;
	if (topo) {
		for (p = topo; p; p = p->prox) {
			if (valor == p->conteudo) {
				return p;
			}
		}
	}
	return NULL;
}

Celula *excluir(int valor, Celula *lista) {
	Celula *p, *pR;

	if (!lista) {
		return lista;
	}

	for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
		if (valor == p->conteudo) {
			//printf("Valor %d localizado\n", p->conteudo);
			break;
		}
	}

	if (!p) {
		printf("Valor %d não localizado\n", valor);
		return lista;
	}

	if (!pR) {
		lista = lista->prox;
	} else if (!p->prox) {
		pR->prox = NULL;
	} else {
		pR->prox = p->prox;
	}
	free(p);
	return lista;
}

Celula *removerFaixa(int menor, int maior, Celula *lista) {
	// validação
	if (!lista) {
		printf("Lista vazia...");

		return NULL;
	}
	if (menor > maior) {
		printf("Invertendo a order...\n");
		int x = menor;
		menor = maior;
		maior = x;
	}
	int tam = contar(lista);
	if (maior > tam) {
		printf("A lista tem %d elementos, alterando reduzindo valor final\n", tam);

		maior = tam - 1;
	}

	printf("Removendo a faixa %d - %d\n", menor, maior);
	Celula *p;
	int i;
	for (p = lista, i = 0; p; p = p->prox, i++) {
		printf("%d ", p->conteudo);
		if (i >= menor && i <= maior) {
			printf("será excluído\n");
			p = excluir(p->conteudo, lista);

			continue;
		}

		printf("não será excluído\n");
	}

	return lista;
}
