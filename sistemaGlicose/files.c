/**
 * @author: Alisson Naimayer (09/04/2020)
 * @Contact: anaimayer3@gmail.com
 * @Compiler: LLVM/Clang
 * @OS: Fedora 31 x86_64
 * @copyright: GPLv2
*/

#include "files.h"

/// setFileName - Define o nome do arquivo para ler
void setFileName() {
	char name[200];
	while( strlen(name) <= 4 ) {
		printf("Nome do arquivo:\n > ");
		scanf("%s", name);

		if( strlen(name) <= 4 ) {
			termYellow(false);
			printf("  - Adicione '.txt' no final do nome\n");
			termDefault();
		}
	}

	strcpy(fileName, name);
}

/// defineFileName - Define o nome do arquivo previamente
/// @param name - char[200] Nome do arquivo
void defineFileName(char name[200]) {
	strcpy(fileName, name);
}

/// readFile - Procura e lê um arquivo
/// @return *FILE || NULL
FILE *readFile(FILE *fileP) {
	setFileName();

	fileP = fopen(fileName, "r");

	if( !fileP ) {
		termRed(true);
		printf("  - Arquivo %s não existe\n", fileName);
		termDefault();

		return NULL;
	}
	termGreen(true);
	printf("  - Arquivo localizado\n");
	termDefault();

	return fileP;
}

/// @attention
void writeToFile() {
	// TODO
}
