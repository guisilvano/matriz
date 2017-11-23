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
 *Busca o ultimo elemento da lista
 */
Linha *buscaUltimo(Linha *lin)
{	
	
	if(lin == NULL){
		return NULL;
  	}
  	
	//se lin->prox for diferente de nulo lin recebe lin-prox
	while(lin->prox != NULL){
   		lin = lin->prox;
  	}
  	
	return lin;
}


/*
 * Insere um valor no final da linha
 */
Linha* insereLinha (Linha *lin, float n)
{
	Linha *novo = new Linha();
	// verifica se houve falha na alocação de memória
	if (novo == NULL){
		printf ("\nFALHA AO ALOCAR MEMORIA");
		exit (0);
	}
	//insere valor
	novo->valor = n;
	novo->prox = NULL;
	//cria nova linha
   	if(lin == NULL){
        lin = novo;

   	} else {
		Linha *ult = buscaUltimo (lin);
    	ult->prox = novo;
   	}

	return lin;
}

/*
 * Finaliza a linha e aloca na estrutura Coluna
 */
Coluna* novaLinha (Coluna *col, Linha *lin)
{	
	Coluna *novo = new Coluna();
	
	// verifica se houve falha na alocação de memória
	if (novo == NULL){
		printf ("\nFALHA AO ALOCAR MEMORIA");
		exit (0);
	}
	// atribui os valores
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

	lin = NULL;

	return col;
}

/*
 * Imprime os valores em graus celcius
 */
void imprimeCelcius (Coluna *col)
{
	Linha  *primeiraLinha = col->linha;
	Coluna *primeiraColuna = col;
	
	while (col != NULL){
		while (col->linha != NULL){
			printf("%.2f\t", col->linha->valor);
			col->linha = col->linha->prox;

		}
		printf("\n");
		col = col->prox;
	}

	col = primeiraColuna;
	col->linha = primeiraLinha;
}

/*
 * Converte e imprime os valores em graus fahrenheit
 */
void converteFahrenheit (Coluna *col)
{
	Linha  *primeiraLinha = col->linha;
	Coluna *primeiraColuna = col;
	
	while (col != NULL){
		while (col->linha != NULL){
			printf("%.2f\t", (col->linha->valor*1.8+32));
			col->linha = col->linha->prox;
		}
		printf("\n");
		col = col->prox;
	}

	col = primeiraColuna;
	col->linha = primeiraLinha;
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
				imprimeCelcius (headC);
				printf("\n");
				converteFahrenheit (headC);
				
				system("pause");

			default: return 0;
		}
	}

	return 0;
}
