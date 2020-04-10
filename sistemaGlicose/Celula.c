/**
 * @author: Alisson Naimayer (09/04/2020)
 * @Contact: anaimayer3@gmail.com
 * @Compiler: LLVM/Clang
 * @OS: Fedora 31 x86_64
 * @copyright: GPLv2
*/

typedef struct node {
	int valor;
	char data[50];
	struct node *prox;
} Celula;

static int generateMax = 100;

/// Mudar valor máximo gerado aleatóriamente pela função popula
/// @param lista *Celula - ponteiro da Celula
/// @return int - numero de elementos exibidos
void mudarNumMaxGerado(int val) {
	if( val <= 0 || val > 1000 ) {
		printf("O valor deve estar entre 0 e 1000");
	}

	generateMax = val;
}

/// @param lista *Celula - ponteiro da Celula
/// @return int - numero de elementos exibidos
int exibir(Celula *lista) {
	Celula *p;
	uint i = 0;
	if( !lista ) {
		printf("Lista vazia.\n");

		return 0;
	}

	for( p = lista; p; p = p->prox ) {
		if( generateMax > 100 ) {
			printf("%03d\n", p->valor);
		} else {
			printf("%02d\n", p->valor);
		}

		i++;
	}

	printf("\n");

	return i;
}

/// exibirLinhas - Quebra linha após certo número
/// @param lista *Celula - ponteiro da Celula
/// @param limit uint - Número máximo de elemento por linha
/// @return int - numero de elementos exibidos
int exibirLinhas(Celula *lista, uint limit) {
	Celula *p;
	uint i = 0;

	if( limit == 0 ) {
		printf("O limite deve ser maior do que zero");

		return 0;
	}

	if( !lista ) {
		printf("Lista vazia.\n");

		return 0;
	}

	for( p = lista; p; p = p->prox ) {
		if( i % limit == 0 ) {
			printf("\n");
		}

		if( generateMax > 100 ) {
			printf("%03d  |  ", p->valor);
		} else {
			printf("%02d  |  ", p->valor);
		}

		i++;
	}

	printf("\n");

	return i;
}

/// @param lista *Celula - Ponteiro da Celula
/// @return uint - Quantidade de elementos na lista
int contar(Celula *lista) {
	Celula *p;
	uint total = 0;
	for( p = lista; p; p = p->prox, total++ );

	return total;
}

/// @param valor int - Valor para ser inserido na lista
/// @param lista *Celula - Ponteiro da Celula
/// @return Celula - Ponteiro da própria lista
Celula *inserir(int valor, Celula *lista) {
	Celula *novo;

	novo = (Celula *) malloc(sizeof(Celula));
	novo->valor = valor;
	novo->prox = lista;

	return novo;
}

/// @param lista *Celula - Ponteiro da Celula
/// @param quantidade uint - Valor para ser inserido na lista
/// @return *Celula - A própria lista
Celula *popula(Celula *lista, uint quantidade) {
	uint i;
	for( i = 0; i < quantidade; i++ ) {
		lista = inserir(rand() % generateMax, lista);
	}

	return lista;
}

/// @param valor int - Valor procurado
/// @param lista *Celula - Ponteiro da Celula
/// @return *Celula - Lista no valor procurado || NULL
Celula *pesquisar(int valor, Celula *lista) {
	Celula *p;

	if( lista ) {
		for( p = lista; p; p = p->prox ) {
			if( valor == p->valor ) {
				return p;
			}
		}
	}

	return NULL;
}

/// @param valor int - Valor para excluir
/// @param lista *Celula - Ponteiro da Celula
/// @return *Celula - A propria lista
Celula *excluir(int valor, Celula *lista) {
	Celula *p, *pR;

	if( !lista ) {
		return lista;
	}

	for( pR = NULL, p = lista; p; pR = p, p = p->prox ) {
		if( valor == p->valor ) {
			break;
		}
	}

	if( !p ) {
		printf("Valor não encontrado\n");

		return lista;
	}
	if( !pR ) {
		lista = lista->prox;
	} else if( !p->prox ) {
		pR->prox = NULL;
	} else {
		pR->prox = p->prox;
	}
	free(p);

	return lista;
}

/// @param lista *Celula - Ponteiro da Celula
/// @return NULL
Celula *destruirLista(Celula *lista) {
	Celula *p, *pR;

	for( pR = lista, p = lista->prox; p; pR = p, p = p->prox ) {
		free(pR);
	}
	free(pR);

	printf("Memória liberada\n");

	return NULL;
}

/// excluirFaixa - Excluir elementos da lista com valor entre $inicio e $fim
/// @param inicio int - Excluir valores maiores &&
/// @param fim int - Excluir valores menores
/// @param lista *Celula - Ponteiro da Celula
/// @return *Celula - A propria lista
Celula *excluirFaixa(int inicio, int fim, Celula *lista) {
	// TODO
	return NULL;
}

/// @param data char[50] - data DD/MM/YYYY para ser inserida na lista
/// @param valor int - Valor para ser inserido na lista
/// @param lista *Celula - Ponteiro da Celula
/// @return Celula - Ponteiro da própria lista
Celula *inserirGlicose(char data[50], int valor, Celula *lista) {
	Celula *novo;
	novo = (Celula *) malloc(sizeof(Celula));

	strcpy(novo->data, data);
	novo->valor = valor;
	novo->prox = lista;

	return novo;
}

/// @param valor int - Ponteiro da Celula
/// @param data char[15] - Ponteiro da Celula
/// @param lista *Celula - Ponteiro da Celula
/// @return *Celula - Ponteiro da própria lista
Celula *inserirGlicoseOrdenado(int valor, char data[15], Celula *lista) {
	Celula *novo;
	Celula *p, *pR;

	novo = (Celula *)malloc(sizeof(Celula));

	novo->valor = valor;
	strcpy(novo->data, data);
	novo->prox = NULL;

	if (!lista) {
		return novo;
	}

	for (pR = NULL, p = lista; p ; pR = p, p = p->prox) {
		if (valor < p->valor) {
			break;
		}
	}

	//printf("Pos encontrada\n");

	if (!pR) {
		novo->prox = p;

		return novo;
	} else if (p == NULL) {
		pR->prox = novo;
	} else {
		pR->prox = novo;
		novo->prox = p;
	}


	return lista;
}

/// exibirLinhasGlicose - Quebra linha após certo número
/// @param lista *Celula - ponteiro da Celula
/// @param limit uint - Número máximo de elemento por linha
/// @return int - numero de elementos exibidos
int exibirLinhasGlicose(Celula *lista, uint limit) {
	Celula *p;
	uint i = 0;

	if( limit == 0 ) {
		printf("O limite deve ser maior do que zero");

		return 0;
	}

	if( !lista ) {
		printf("Lista vazia.\n");

		return 0;
	}

	for( p = lista; p; p = p->prox ) {
		if( i % limit == 0 ) {
			printf("\n");
		}

		if( generateMax > 100 ) {
			printf("%s: %03d  |  ", p->data, p->valor);
		} else {
			printf("%s: %02d  |  ", p->data, p->valor);
		}

		i++;
	}

	printf("\n");

	return i;
}
