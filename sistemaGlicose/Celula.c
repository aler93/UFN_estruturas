/**
 * @Developer: Alisson Naimayer (09/04/2020)
 * @Contact: anaimayer3@gmail.com
 * @Compiler: LLVM/Clang
 * @OS: Fedora 31 x64
*/

typedef struct node {
	int valor;
	char text[50];
	struct node *prox;
} Celula;

static int generateMax = 100;

/// Mudar valor máximo gerado aleatóriamente pela função popula
/// @param lista *Celula - ponteiro da Celula
/// @return int - numero de elementos exibidos
void mudarNumMaxGerado(int val) {
	if( val <= 0 ) {
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
			printf("%03d  |  ", p->valor);
		} else {
			printf("%02d  |  ", p->valor);
		}

		i++;
	}

	printf("\n");

	return i;
}

/// exibirLinhas - Quebra linha após certo número
/// @param lista *Celula - ponteiro da Celula
/// @param maxLinha uint - Número máximo de elemento por linha
/// @return int - numero de elementos exibidos
int exibirLinhas(Celula *lista, uint maxLinha) {
	Celula *p;
	uint i = 0;

	if( !lista ) {
		printf("Lista vazia.\n");

		return 0;
	}

	for( p = lista; p; p = p->prox ) {
		if( i % maxLinha == 0 ) {
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

	return NULL;
}

/// @param inicio int - Excluir valores maiores &&
/// @param fim int - Excluir valores menores
/// @param lista *Celula - Ponteiro da Celula
/// @return *Celula - A propria lista
Celula *excluirFaixa(int inicio, int fim, Celula *lista) {
	// TODO
	return NULL;
}
