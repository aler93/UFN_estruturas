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
			printf("Au revoir\n");
			break;
		}
		if( input == 1 ) {
			arquivo = readFile(arquivo);
			lista = fileToMemory(arquivo, lista);
			continue;
		}
		if( input == 2 ) {
			exibirLinhasGlicose(lista, 3);
			continue;
		}
		if( input == 3 ) {
			calcularMedia(lista);
			continue;
		}
		if( input == 4 ) {
			// TODO
			continue;
		}
		if( input == 5 ) {
			menorValor(lista);
			continue;
		}
		if( input == 6 ) {
			maiorValor(lista);
			continue;
		}
		if( input == 7 ) {
			destruirLista(lista);
			continue;
		} else {
			termYellow(true);
			printf("Comando não reconhecido\n");
		}
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
	printf("  - Escrevendo arquivo na memória...\n");
	while( !feof(arquivo)) {
		line++;
		fscanf(arquivo, "%d/%d/%d\t%d", &m, &d, &y, &valor);
		corrigirData(data, d, m, y);

		destino = inserirGlicose(data, valor, destino);
	}

	fclose(arquivo);

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
		printf("A media dos %d dias é %.2f\n\n", qnt, media);
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
		printf("O menor valor é %d, no dia %s\n\n", menor->valor, menor->data);

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
		printf("O maior valor é %d, no dia %s\n\n", maior->valor, maior->data);

		return maior->valor;
	}

	return 0;
}
