/*
    Arquivo texto (plain text)

    TIPOS espec�ficos:
        - FILE * nomeVariavel;
        . vari�vel que aponta para um endere�o de um arquivo em disco
        . conceito de procura��o

    Aberturas:
        - fopen
        . abrir no modo leitura "r" (read)
        . abrir no modo apendar "a" (append)
        . abrir no modo criar/escrever "w" (write)
        . abrir significa fazer o ponteiro procurador apontar para o
          endere�o do arquivo no disco

    Fechamento:
        - fclose
        . � neste momento que todo o conte�do colocado no procurador
          vai para o disco

    Grava��o em disco
        - fflush

    Leitura
        - fscanf
        - fgets
        - fgetc

    Escrever/Gravar
        - fprintf
        - fputs
        - fputc

    CURIOSIDADES:
        . EOF diferente da fun��o feof()
        . EOF � um s�mbolo de caracter para final de arquivo,
          usado nas leitura caracter a caracter
        . feof() � uma fun��o que retorna se um procurador
          chegou ao final do arquivo

*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    //programa que le um nome de arquivo e se existe exibe seu conteudo
    //na tela. OBS.: arquivos text
    FILE *procurador;
    char nomeArquivo[200];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    procurador = fopen(nomeArquivo,"r");

    if (!procurador) {
        printf("Arquivo nao encontrado!\n");
        exit(0);
    }
    printf("Arquivo localizado e sendo aberto...\n");

    char linha[200];
    int contaLinhas = 0;
    do {
        contaLinhas++;
        fgets(linha,200,procurador);
        printf("%s", linha);
    } while(!feof(procurador));

    printf("Este arquivo tem %d linhas\n", contaLinhas);
    fclose(procurador);
    return 1;
}
