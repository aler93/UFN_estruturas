/**
 * @author: Alisson Naimayer (09/04/2020)
 * @Contact: anaimayer3@gmail.com
 * @Compiler: LLVM/Clang || GCC
 * @OS: Fedora 31 x86_64
 * @copyright: GPLv2
*/

void termDefault() {
	printf("\033[0m");
}

void termRed(bool bold) {
	if(bold) {
		printf("\033[0;31m"); return;
	}
	printf("\033[0;31m");
}

void termGreen(bool bold) {
	if(bold) {
		printf("\033[1;32m"); return;
	}
	printf("\033[0;32m");
}

void termYellow(bool bold) {
	if(bold) {
		printf("\033[1;33m"); return;
	}
	printf("\033[0;33m");
}

void termBlue(bool bold) {
	if(bold) {
		printf("\033[1;34m"); return;
	}
	printf("\033[0;34m");
}

void termMagenta(bool bold) {
	if(bold) {
		printf("\033[1;35m"); return;
	}
	printf("\033[0;35m");
}

void termCyan(bool bold) {
	if(bold) {
		printf("\033[1;36m"); return;
	}
	printf("\033[0;36m");
}
