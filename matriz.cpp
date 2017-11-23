#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>

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


Linha *buscaUltimo(Linha *lin)
{
	if(lin == NULL){
		return NULL;
  	}
  	
	while(lin->prox != NULL){
   		lin = lin->prox;
  	}
  	
	return lin;
}


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


void converteFahrenheit (Coluna *col)
{
	Coluna *tmp = col;
	
	while (col != NULL){
		while (col->linha != NULL){
			printf("%.2f\t", (col->linha->valor*1.8+32));
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
	
	int opt;

	printf("CONVERSOR CELCIUS -> FAHRENHEIT"
		"\n 1) Inserir temperatura na linha"
		"\n 2) Terminar linha atual/nova linha em branco"
		"\n 3) Converter para graus fahrenheit"
		"\n 0) Ajuda\n");

	while (true){
		printf("\n>>");
		scanf("%d", &opt);
		
		switch (opt){
			case 1:	
				float n;
			
				printf("Informe o valor: ");
				scanf("%f", &n);

				headL = insereLinha (headL, n);

				break;
			
			case 2:
				headC = novaLinha (headC, headL);
				headL = NULL;
				
				printf("Linha finalizada!\n");

				break;
			
			case 0:
				printf("Inserir as temperaturas em °C utilizando a opção 1, "
				"assim que todos os valores de uma linha forem inseridos "
				"utilizar a opção 2 para criá-la e iniciar uma nova linha com "
				"novos valores."
				"\nUtilizar a opção 3 para finalizar o programa e converter as unidades."
				"\nPressione qualquer outra tecla para terminar o programa.\n");
			
				break;

			case 3:
				printf("\nTemperaturas (°F): \n");
				converteFahrenheit (headC);
				system ("pause");
			default: return 0;
		}
	}

	return 0;
}
