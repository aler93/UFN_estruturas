/**
 * @Developer: Alisson Naimayer (09/04/2020)
 * @Contact: anaimayer3@gmail.com
 * @Compiler: LLVM/Clang
 * @OS: Fedora 31 x64
*/

#include "files.h"

/// @setFileName: Define o nome do arquivo para ler
void setFileName() {
	char name[200];
	printf("Nome do arquivo:\n > ");
	scanf("%s", name);

	strcpy(fileName, name);
}

/// @defineFileName: Define o nome do arquivo previamente
void defineFileName(char name[200]) {
	strcpy(fileName, name);
}

void readFile() {
	while( strlen(fileName) == 0 ) {
		setFileName();
	}

	termRed(true);
	printf("Abrindo arquivo: %s\n", fileName);
	termDefault();
}

void writeToFile() {
	// TODO
}
