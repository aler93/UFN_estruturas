#include <stdio.h>
#include <stdlib.h>

int main() {
	//programa que le um nome de arquivo e se existe exibe seu conteudo
	//na tela. OBS.: arquivos text
	FILE *procurador;
	char nomeArquivo[200];

	printf("Digite o nome do arquivo: ");
	scanf("%s", nomeArquivo);

	procurador = fopen(nomeArquivo, "r");

	if (!procurador) {
		printf("Arquivo nao encontrado!\n");
		exit(0);
	}
	printf("Arquivo localizado e sendo aberto...\n");

	float x, y;
	int massa;
	int contaLinhas = 0;
	int conseguiu;
	do {
		contaLinhas++;
		conseguiu = fscanf(procurador, "%f %f %d", &x, &y, &massa);
		if (!conseguiu) break;
		printf("%.2f %.2f %d\n", x, y, massa);
	} while (!feof(procurador));

	printf("Este arquivo tem %d linhas\n", contaLinhas);
	fclose(procurador);
	return 1;
}
