#include<stdio.h>
#include<stdlib.h>

/*
 * TODO: Implementar a estrutura Coluna, que guarda uma estrutura Linha
 */

struct Linha 
{
	float valor;								
	struct Linha *prox;
};

struct Coluna 
{
	struct Linha;
	struct Coluna *prox;
};

/*
 * Imprime a linha atual
 */
Linha *imprimeLinha (Linha *lin)
{
	
	printf ("\nimprimeLinha: ");

	if (lin == NULL)
		printf ("Vazio.");

	Linha *l = lin;
	l = lin;

	while (l != NULL){
		printf ("%.2f ", l->valor);
		l = l->prox;
	}

	return l;
}

/*
 * Insere um valor no inicio da linha
 */
Linha* insereInicioLinha (Linha *lin, float n)
{

	printf ("insereInicio: ");
	
	struct Linha *novo = (struct Linha*) malloc(sizeof(struct Linha));
	
	if (novo == NULL){
		printf ("\nFALHA AO ALOCAR MEMORIA");
		exit(0);
	}

	novo->valor = n;
	novo->prox = NULL;
	
	printf ("%.2f ", novo->valor);

	return novo;
}


int main (int argc, char *argv[])
{

	Linha *headL = NULL;					//head linha
	Linha *inicioL = headL;					//inicio linha

	headL = insereInicioLinha (headL, 12);
	headL = insereInicioLinha (headL, 13);
	
	imprimeLinha (inicioL);
	
	printf ("\nMain: %.2f", headL->valor);

	return 0;
}
