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
void imprimeLinha (Linha *lin)
{
	if (lin == NULL)
		printf ("\nVazio.");

	printf("\n");

	while (lin != NULL){
		printf ("%.2f ", lin->valor);
		lin = lin->prox;
	}
}

/*
 * Insere um valor no inicio da linha
 */
Linha* insereInicioLinha (Linha *lin, float n)
{
	struct Linha *novo = (struct Linha*) malloc(sizeof(struct Linha));
	

	if (novo == NULL){
		printf ("\nFALHA AO ALOCAR MEMORIA");
		exit (0);
	}

	novo->valor = n;
	novo->prox = lin;
	
	return novo;
}


int main (int argc, char *argv[])
{
	Linha *headL = NULL;					//head linha

	imprimeLinha (headL);

	headL = insereInicioLinha (headL, 12);
	headL = insereInicioLinha (headL, 13);
	
	imprimeLinha (headL);

	return 0;
}
