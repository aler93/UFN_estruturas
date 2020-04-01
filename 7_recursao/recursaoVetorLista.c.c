#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int dado;
	struct nodo *prox;
} Celula;


int somaR(int *v, int n) {
	if (n > 0) {
		return v[n - 1] + somaR(v, n - 1);
	}
	return 0;
}

int maiorR(int *v, int n) {
	if (n > 1) {
		int vemDeCima = maiorR(v, n - 1);
		if (vemDeCima > v[n - 1]) return vemDeCima;
		return v[n - 1];
	}
	return v[n - 1];

}

int contaCelulasR(Celula *l) {
	if (l) {
		return 1 + contaCelulasR(l->prox);
	}
	return 0;
}

int somaCelulasR(Celula *l) {
	if (l) {
		return l->dado + somaCelulasR(l->prox);
	}
	return 0;
}

int localizaR(int valor, Celula *l) {
	if (l) {
		if (valor == l->dado) return 1;
		/*else*/ return localizaR(valor, l->prox);
	}
	return 0;
}

Celula *inserirR(int valor, Celula *l) {
	if (l) {
		l->prox = inserirR(valor, l->prox);
		return l;
	} else {
		Celula *novo = (Celula *) malloc(sizeof(Celula));
		novo->dado = valor;
		novo->prox = NULL;
		return novo;
	}
}

void exibirR(Celula *l) {
	if (l) {
		printf("%d\t", l->dado);
		exibirR(l->prox);
	}
}

int main() {
	Celula *lista = NULL;

	int vetor[] = {12, 1, 5};
	printf("A soma dos elementos do vetor eh %d\n", somaR(vetor, 3));
	printf("O maior elemento do vetor eh %d\n", maiorR(vetor, 3));

	lista = inserirR(10, lista);
	lista = inserirR(12, lista);
	lista = inserirR(3, lista);

	exibirR(lista);

	return 0;
}

/*
RECURS�O -> repeti��o sem instru��es de controle, mas sim
com autochamamento do m�todo (empilhamento/desempilhamento
de processos)

    Tipos -> void
          -> return

    Conceitos
          -> crit�rios de repeti��o
            -> inicializa��o da vari�vel de controle (par�metro)
            -> teste de parada (� um if no in�cio do m�todo)
            -> transforma��o da vari�vel de controle
                -> PONTO DE RECURS�O
          -> execu��o de c�digo ao empilhar
            -> instru��es codificadas antes da chamada do m�todo
          -> execu��o de c�digo ao desempilhar
            -> instru��es codificadas depois da chamada do m�todo


void metodo(<tipo> variavelControle) {
    if (variavelControle) {
        <instru��o1>;
        metodo(variavelControle transformada);
        <instru��oN>
    }
}

void imprimeSequeciaR(int ini, int fim) {
   if (ini <= fim) {
        printf("%d\t", ini);
        imprimeSequenciaR(ini + 1,fim);
   }
}

void imprimeSequeciaR(int ini, int fim) {
   if (ini <= fim) {
        imprimeSequenciaR(ini,fim - 1);
        printf("%d\t", fim);
   }
}


main() {
    imprimeSequencia(6,15);
}
*/
