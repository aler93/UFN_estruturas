/**
 * @Developer: Alisson Naimayer (09/04/2020)
 * @Contact: anaimayer3@gmail.com
 * @Compiler: LLVM/Clang
 * @OS: Fedora 31 x64
*/

#include "sistemaGlicose.h"

int main() {
	new();

	defineFileName("dados_glicose.txt");
	readFile();

	return 0;
}

void new() {
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));
	mudarNumMaxGerado(500);
}
