//
// Created by aler on 09/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

void exibir(Celula *lista) {
	Celula *p;
	if( !lista ) {
		printf("Lista vazia.\n");
		return;
	}
	for( p = lista; p->prox != lista; p = p->prox ) {
		printf("%d\t", p->conteudo);
	}
	printf("%d\n", p->conteudo);
}

int contar(Celula *lista) {
	Celula *p;
	int total = 0;
	if( !lista ) {
		printf("Lista vazia.\n");
		return 0;
	}
	for( p = lista; p->prox != lista; p = p->prox ) {
		total++;
	}
	total++;

	return total;
}

Celula *localizar(int valor, Celula *lista) {
	Celula *p;
	if( !lista ) {
		printf("Lista vazia.\n");
		return NULL;
	}
	for( p = lista; p->prox != lista; p = p->prox ) {
		if( valor == p->conteudo ) {
			return p;
		}
	}
	if( valor == p->conteudo ) {
		return p;
	}
	return NULL;
}

//inserindo na lista sem ordenacao, sempre na última posição
Celula *inserir(int valor, Celula *lista) {
	Celula *p, *pR, *novo;
	novo = (Celula *) malloc(sizeof(Celula));
	novo->conteudo = valor;
	novo->prox = novo;

	if( !lista ) return novo; //se for o único, já retorno o novo

	for( pR = NULL, p = lista; p->prox != lista; pR = p, p = p->prox ) {
		if( valor < p->conteudo ) {
			break;
		}
	}

	if( p->prox == lista && valor > p->conteudo ) { //é o ultimo elemento
		p->prox = novo;
		novo->prox = lista;
	} else if( !pR ) { //if (p == lista) ou seja, é o primeiro elemento
		novo->prox = lista; //novo->prox = p;

		for( ; p->prox != lista; p = p->prox );

		p->prox = novo;
		return novo;
	} else { //é um elemento de meio
		pR->prox = novo;
		novo->prox = p;
	}
	return lista;
}

Celula *popular(Celula *lista, int quantidade) {
	srand(time(NULL));
	int i;
	int numero;
	printf("Números sorteados:\n");
	for( i = 0; i < quantidade; i++ ) {
		numero = rand() % 10;
		printf("%d\t", numero);
		lista = inserir(numero, lista);
	}
	printf("\n");

	return lista;
}

Celula *excluir(int valor, Celula *lista) {
	Celula *p, *pR;
	if( !lista ) { //lista vazia... nada é excluído
		return lista;
	}
	for( pR = NULL, p = lista; p->prox != lista; pR = p, p = p->prox ) {
		if( valor == p->conteudo ) {
			//vamos excluir, mas antes, vamos descobrir se é primeiro ou do meio
			if( p == lista ) { //if (!pR) é o primeiro
				//código para eliminar o primeiro
				for( ; p->prox != lista; p = p->prox );

				lista = lista->prox; //este código deve ser realizado após o for.....
				p->prox = lista;
				free(p);
				return lista;
			} else {
				//código para eliminar alguém no meio
				//o mesmo código usado em listas simples
				pR->prox = p->prox;
				free(p);
				return lista;
			}
		}
	}
	//se saiu do for porque chegou no último elemento, assim, devemos testar se o último valor vai ser removido
	if( valor == p->conteudo ) {
		//vamos excluir sabendo que é o último elemento
		pR->prox = lista;
		free(p);
	}

	return lista;
}

Celula *destruirLista(Celula *lista) {
	Celula *pR, *p;

	if (!lista) return lista;

	for (pR = lista, p = lista->prox; p->prox != lista ; pR = p, p = p->prox) {
		free(pR);
	}
	free(pR);
	free(p);

	return NULL;
}

Celula *excluirTodasOcorrencias(Celula *lista, int valor) {
	Celula *p;

	for( p = lista; p; p = p->prox ) {
		if( p->conteudo == valor ) {
			p = excluir(valor, p);
		}
	}

	return lista;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	Celula *lista = NULL;

	lista = popular(lista, 15);
	lista = excluirTodasOcorrencias(lista, 2);

	exibir(lista);

	return 1;
}
