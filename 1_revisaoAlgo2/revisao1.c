//Entretanto, os n�meros n�o podem repetir. Ao final, exibir o vetor.
#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int main() {
	int vetor[TAM];
	int contador;
	int numero;
	int existe; //booleano para verificar se numero jah inserido

	//inicializacao do vetor com -1
	for (int i = 0; i < TAM; i++) {
		vetor[i] = -1;
	}

	contador = 0;
	do {
		do {
			existe = 0;
			printf("Informe um numero inteiro: ");
			scanf("%d", &numero);

			for (int i = 0; vetor[i] != -1; i++) {
				if (numero == vetor[i]) {
					existe = 1; //localizou
					break;
				}
			}
			if (existe) printf("Numero jah digitado. \n");
		} while (existe);


		vetor[contador] = numero;
		contador++;

	} while (contador < TAM);


	//exibicao do vetor
	for (int i = 0; i < TAM; i++) {
		printf("%d\t", vetor[i]);
	}


	return 1;
}
