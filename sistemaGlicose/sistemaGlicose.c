/**
 * @author: Alisson Naimayer (09/04/2020)
 * @Contact: anaimayer3@gmail.com
 * @Compiler: LLVM/Clang
 * @OS: Fedora 31 x86_64
 * @copyright: GPLv2
*/

#include "sistemaGlicose.h"

int main() {
	new();

	int input = 0;
	FILE *arquivo;
	Celula *lista = NULL;

	while( true ) {
		printMenu();
		scanf("%d", &input);

		if( input == 0 ) {
			termCyan(true);
			printf("\nSo long; Au revoir; Tchau\n");
			if( lista ) {
				destruirLista(lista);
			}
			break;
		} else if( input == 1 ) {
			arquivo = readFile(arquivo);
			if( arquivo ) {
				lista = fileToMemory(arquivo, lista);
			}
		} else if( input == 2 ) {
			exibirLinhasGlicose(lista, limitCols);
		} else if( input == 3 ) {
			calcularMedia(lista);
		} else if( input == 4 ) {
			mediana(lista);
		} else if( input == 5 ) {
			menorValor(lista);
		} else if( input == 6 ) {
			maiorValor(lista);
		} else if( input == 7 ) {
			lista = destruirLista(lista);
		} else if( input == 8 ) {
			exibirOrdenadoGlicose(lista);
		} else if( input == 9 ) {
			lista = limitarLeitura(lista);
		} else {
			termYellow(true);
			printf("Comando não encontrado\n");
		}
		termDefault();
		printf("\nPressione enter para continuar");
		while( getchar() != '\n' );
		getchar();
	}

	termDefault();
	printf("\n\n");
	return 0;
}

void new() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	mudarNumMaxGerado(500);
}

void printMenu() {
	termBlue(true);
	printf("Escolha uma opção:\n");
	termDefault();
	printf("\t 1 - Ler arquivo\n");
	printf("\t 2 - Exibir dados na memória\n");
	printf("\t 3 - Calcular média dos dados glicêmicos\n");
	printf("\t 4 - Calcular mediana\n");
	printf("\t 5 - Menor valor glicêmico\n");
	printf("\t 6 - Maior valor glicêmico\n");
	printf("\t 7 - Remover lista da memória\n");
	printf("\t 8 - Exibir lista ordenada por valor da glicose\n");
	printf("\t 9 - Impor limite de linhas para leitura\n");
	printf("\t 0 - sair\n");
	printf("Escolha uma opção\n > ");
}

/// fileToMemory - Copia o conteúdo de um arquivo para a memória do sistema
/// @param arquivo FILE - Ponteiro para arquivo
/// @param destino Celula - Lista onde será armazenado o arquivo
Celula *fileToMemory(FILE *arquivo, Celula *destino) {
	int read, line = 0;
	int valor;
	char data[15];
	int d, m, y;

	termGreen(false);
	printf("    - Escrevendo arquivo na memória...\n");
	while( !feof(arquivo)) {
		line++;
		fscanf(arquivo, "%d/%d/%d\t%d", &m, &d, &y, &valor);
		corrigirData(data, d, m, y);

		destino = inserirGlicose(data, valor, destino);

		if( limitLines > 0 && line >= limitLines ) {
			break;
		}
	}

	fclose(arquivo);
	printf("    - Pronto...\n");

	return destino;
}

/// corrigirData - Altera o formato da data para DD/MM/YYYY
/// @param data char[15] - string onde a data será escrita
/// @param dia - int
/// @param mes - int
/// @param ano - int
void corrigirData(char data[15], int dia, int mes, int ano) {
	sprintf(data, "%02d/%02d/%04d", dia, mes, ano);
}

/// @param lista Celula - lista contendo os dados
float calcularMedia(Celula *lista) {
	Celula *p;
	int total = 0, qnt = 0;
	float media;

	if( lista ) {
		for( p = lista; p; p = p->prox, qnt++ ) {
			total = total + p->valor;
		}

		media = (float) total / qnt;
		termGreen(false);
		printf("A media dos %d dias é %.2f\n", qnt, media);
	}

	return media;
}

/// @param lista Celula - lista contendo os dados
int menorValor(Celula *lista) {
	Celula *p;
	Celula *menor = NULL;

	if( lista ) {
		for( p = lista; p; p = p->prox ) {
			if( menor == NULL ) {
				menor = p;
				menor->valor = p->valor;

				continue;
			}
			if( p->valor < menor->valor ) {
				menor = p;
				menor->valor = p->valor;
			}
		}

		termGreen(false);
		printf("O menor valor é %d, no dia %s\n", menor->valor, menor->data);

		return menor->valor;
	}

	return 0;
}

/// @param lista Celula - lista contendo os dados
int maiorValor(Celula *lista) {
	Celula *p;
	Celula *maior = NULL;

	if( lista ) {
		for( p = lista; p; p = p->prox ) {
			if( maior == NULL ) {
				maior = p;
				maior->valor = p->valor;

				continue;
			}
			if( p->valor > maior->valor ) {
				maior = p;
				maior->valor = p->valor;
			}
		}

		termGreen(false);
		printf("O maior valor é %d, no dia %s\n", maior->valor, maior->data);

		return maior->valor;
	}

	return 0;
}

void mediana(Celula *lista) {
	if( lista ) {
		Celula *p = NULL, *ordenada;

		ordenada = (Celula *) malloc(sizeof(Celula));

		for( p = lista; p; p = p->prox ) {
			if( p == lista ) {
				ordenada->valor = p->valor;
				strcpy(ordenada->data, p->data);
				ordenada->prox = NULL;

				continue;
			}

			ordenada = inserirGlicoseOrdenado(p->valor, p->data, ordenada);
		}

		int tam = contar(ordenada);
		int meio = tam / 2;
		int i = 0;
		if( tam % 2 == 0 ) {
			printf("Lista par, pos meio %d e %d = ", meio - 1, meio);

			Celula *pR;
			for( pR = NULL, p = ordenada; p; pR = p, p = p->prox ) {
				if( i == meio ) {
					printf("%d e %d, nos dias %s e %s, respectivamente\n",
						   p->valor,
						   pR->valor,
						   p->data,
						   pR->data
					);

					break;
				}
				i++;
			}
		} else {
			printf("Lista ímpar, posição do meio %d = ", meio);
			for( p = ordenada; p; p = p->prox ) {
				if( i == meio ) {
					printf("%d, no dia %s\n", p->valor, p->data);

					break;
				}
				i++;
			}
		}

		return;
	}

	printf("Lista não definida\n");
}

Celula *limitarLeitura(Celula *lista) {
	int input = -1;
	termBlue(true);
	printf("Máximo de linhas para ler (-1 = ilimitado):\n > ");
	termBlue(false);
	scanf("%d", &input);

	limitLines = input;
	termBlue(true);
	printf("Limite alterado.\n");
	termDefault();

	if( lista ) {
		lista = destruirLista(lista);
	}

	return lista;
}

/// Apenas exibe, não altera a lista original
void exibirOrdenadoGlicose(Celula *lista) {
	if( lista ) {
		Celula *p = NULL, *ordenada;

		ordenada = (Celula *) malloc(sizeof(Celula));

		for( p = lista; p; p = p->prox ) {
			if( p == lista ) {
				ordenada->valor = p->valor;
				strcpy(ordenada->data, p->data);
				ordenada->prox = NULL;

				continue;
			}

			ordenada = inserirGlicoseOrdenado(p->valor, p->data, ordenada);
		}

		exibirLinhasGlicose(ordenada, limitCols);

		return;
	}

	printf("Lista não definida\n\n");
}
