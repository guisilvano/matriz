#include <stdio.h>
#include <stdlib.h>

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

struct Coluna  *alocaColuna() 
{
	return (Coluna *) malloc(sizeof(struct Coluna));
}

struct Linha  *alocaLinha()
{
	return (Linha *) malloc(sizeof(struct Linha));
}

void liberaMemoriaColuna(Coluna *Col)
{
	Coluna *Aux,*Ant;
 	if (Col != NULL)
   	{ 
		Aux = Col;
	 	while (Aux != NULL)
	 	{ 
			Ant = Aux;
	   		Aux = Aux->prox;
	   		free(Ant);
	 	}
   }
}

void liberaMemoriaLinha(struct Linha *lin)
{
	Linha *aux,*ant;
 	if(lin != NULL)
   	{ 
		aux = lin;
	 	while (aux->prox != NULL)
	 	{
			ant = aux;
	   		aux = aux->prox;
	   		free(ant);
	 	}
   }
}

float ConverteCelsiusParaFahremheit(float celsius)
{
	return (9*celsius+160)/5;
}

void Inserir( struct Linha *cabeca )
{
	struct Linha *aux, *novo;
	
	aux = cabeca;
	
	while ( aux->prox != NULL ) 
	{
		aux = aux->prox;
	}
	
	novo = alocaLinha ();
	
	printf ("Digite a temperatura: ");
	scanf("%f", &novo->valor);
	novo->prox = NULL;
	
	aux->prox = novo;
}

void Listar(struct Linha *Cabecalho)
{ 
	float grausFahrenheit = 0;
	Linha *aux;
  	aux = Cabecalho;
  	while (aux != NULL)
    {
    	grausFahrenheit = ConverteCelsiusParaFahremheit(aux->valor);
    	printf("-- %d - %f - %d | \n", aux, grausFahrenheit, aux->prox); //getche();
       	aux = aux->prox;
    } 
  	printf("\n");
}

int main() {

	int i = 0;
	struct Linha lin;
	lin.prox = NULL;

	do {
		printf("\n 1 - Inserir");
		printf("\n 2 - Listar");
		printf("\n 3 - FIM");
		printf("\n--> ");
		scanf("%d", &i);
		if (i == 1) Inserir(&lin); 
		if (i == 2) Listar(&lin);
		if (i == 3) break;
	}while(i);

	liberaMemoriaLinha(&lin);
	return 0;
}
