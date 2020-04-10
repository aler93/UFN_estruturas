/**
 * @author: Alisson Naimayer (09/04/2020)
 * @Contact: anaimayer3@gmail.com
 * @Compiler: LLVM/Clang
 * @OS: Fedora 31 x86_64
 * @copyright: GPLv2
*/

#ifndef UFN_ESTRUTURAS_SISTEMAGLICOSE_H
#define UFN_ESTRUTURAS_SISTEMAGLICOSE_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#include "Celula.c"
#include "terminalColor.c"
#include "files.c"

void new();
void printMenu();
void mediana(Celula *lista);
void exibirOrdenadoGlicose(Celula *lista);
void corrigirData(char data[15], int dia, int mes, int ano);

int menorValor(Celula *lista);
int maiorValor(Celula *lista);

float calcularMedia(Celula *lista);

Celula *limitarLeitura(Celula *lista);
Celula *fileToMemory(FILE *arquivo, Celula *destino);

int limitLines = -1;
int limitCols = 3;

#endif //UFN_ESTRUTURAS_SISTEMAGLICOSE_H
