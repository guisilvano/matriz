#include<stdio.h>
#include<stdlib.h>


struct Linha 
{
	float valor;								
	struct Linha *prox;
};


struct Coluna 
{
	struct Linha *linha;
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


Linha *buscaUltimo(Linha *lin)
{
	if(lin == NULL){
		return NULL;
  	}
  	
	//busca o último elemento inserido na linha
	while(lin->prox != NULL){
   		lin = lin->prox;
  	}
  	
	return lin;
}


/*
 * Insere um valor no inicio da linha
 */
Linha* insereLinha (Linha *lin, float n)
{
	Linha *novo = new Linha();

	if (novo == NULL){
		printf ("\nFALHA AO ALOCAR MEMORIA");
		exit (0);
	}

	novo->valor = n;
	novo->prox = NULL;
	
   	if(lin == NULL){
        lin = novo;

   	} else {
        
		Linha *ult = buscaUltimo (lin);

    	ult->prox = novo;
   	}

	return lin;
}


Coluna* novaLinha (Coluna *col, Linha *lin)
{
	Coluna *novo = new Coluna();

	if (novo == NULL){
		printf ("\nFALHA AO ALOCAR MEMORIA");
		exit (0);
	}

	novo->linha = lin;
	novo->prox = NULL;
	
   	if(col == NULL){
        col = novo;

   	} else {
        
		Coluna *ult = col;
		while (ult->prox != NULL){
			ult = ult->prox;
		}

    	ult->prox = novo;
   	}

	return col;
}


void imprimeMatriz (Coluna *col)
{
	while (col != NULL){
		while (col->linha != NULL){
			printf("%.2f ", col->linha->valor);
			col->linha = col->linha->prox;

		}

		printf("\n");
		col = col->prox;
	}

}


void converteFahrenheit (Coluna *col)
{
	while (col != NULL){
		while (col->linha != NULL){
			printf("%.2f ", (col->linha->valor*1.8+32));
			col->linha = col->linha->prox;
		}

		printf("\n");
		col = col->prox;
	}
}


int main (int argc, char *argv[])
{
	Linha *headL = NULL;					//head linha
	Coluna *headC = NULL;					//head coluna
	
	headL = insereLinha (headL, 11);
	headL = insereLinha (headL, 12);
	headL = insereLinha (headL, 13);
	
	headC = novaLinha (headC, headL);
	headL = NULL;

	headL = insereLinha (headL, 21);
	headL = insereLinha (headL, 22);
	headL = insereLinha (headL, 23);

	headC = novaLinha (headC, headL);
	headL = NULL;

	headL = insereLinha (headL, 31);
	headL = insereLinha (headL, 32);
	headL = insereLinha (headL, 33);

	headC = novaLinha (headC, headL);
	headL = NULL;

	headL = insereLinha (headL, 41);
	headL = insereLinha (headL, 42);
	headL = insereLinha (headL, 43);

	headC = novaLinha (headC, headL);
	headL = NULL;

	imprimeMatriz(headC);
	//converteFahrenheit (headC);
	
	return 0;
}
