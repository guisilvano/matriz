struct Linha
{
	float valor;								\
	struct Linha *prox;
};

struct Coluna 
{
	struct Linha *linha;
	struct Coluna *prox;
};

void insereLinha (Coluna *cabeca, float n)
{
	Coluna * coluna = cabeca;
	Linha *novaLinha = new Linha();
	
	// verifica se houve falha na alocação de memória
	if (novaLinha == NULL){
		printf ("\nFALHA AO ALOCAR MEMORIA");
		exit (0);
	}
	
	//insere valor
	novaLinha->valor = n;
	novaLinha->prox = NULL;

	while(coluna->prox != NULL){
		coluna = coluna->prox;
	}
	
	if(coluna->linha == NULL){
		coluna->linha = novaLinha;
	}
	else{
		Linha *linha = coluna->linha;
		while(linha->prox != NULL){
			linha = linha->prox;	
		}
		
		linha->prox = novaLinha;
	}
}

void insereColuna (Coluna *cabeca)
{	
	Coluna *novaColuna = new Coluna();
	Coluna *coluna = cabeca;
	
	// verifica se houve falha na alocação de memória
	if (novaColuna == NULL){
		printf ("\nFALHA AO ALOCAR MEMORIA");
		exit (0);
	}
	
	novaColuna->linha = NULL;
	novaColuna->prox = NULL;

   	if(coluna == NULL){
        coluna = novaColuna;
   	} else {
		while (coluna->prox != NULL){
			coluna = coluna->prox;
		}
    	coluna->prox = novaColuna;
   	}
}

void imprimeCelsius (Coluna *cabeca, int totalElementos)
{
	Coluna *coluna = cabeca;

	while (coluna->prox != NULL){
		Linha *linha = coluna->linha;
		int elementos = 0;
		
		while (linha != NULL){
			printf("%.2f\t", linha->valor);
			linha = linha->prox;

			elementos++;
		}

		while (elementos < totalElementos){
			printf("--\t");
			elementos++;
		}

		printf("\n");
		coluna = coluna->prox;
	}
}

void converteFahrenheit (Coluna *cabeca, int totalElementos)
{
	Coluna *coluna = cabeca;

	while (coluna->prox != NULL){
		Linha *linha = coluna->linha;
		int elementos = 0;
		
		while (linha != NULL){
			printf("%.2f\t", (linha->valor*1.8+32));
			linha = linha->prox;

			elementos++;
		}

		while (elementos < totalElementos){
			printf("--\t");
			elementos++;
		}

		printf("\n");
		coluna = coluna->prox;
	}
}

void liberarMemoria(Coluna *cabeca)
{
	Coluna *coluna,*colunaAnterior;
 	if(cabeca != NULL)
   	{
		coluna = cabeca;
	 	while (coluna != NULL)
	 	{
	 		Linha *linha, *linhaAnterior;
			linha = coluna->linha;
	 		while (linha != NULL)
		 	{
				linhaAnterior = linha;
		   		linha = linha->prox;
		   		free(linhaAnterior);
		 	}
			colunaAnterior = coluna;
	   		coluna = coluna->prox;
	   		free(colunaAnterior);
	 	}
   }
}

void Listar(Coluna *cabeca)
{ 
	Coluna *coluna = cabeca;
	
	// enquanto coluna for diferente de nulo entra no while e calcula a variavel passando para fahrenheit
	while (coluna != NULL){
		Linha *linha = coluna->linha;
		while (linha != NULL){
			printf("-- %d - %f - %d | \n", linha, linha->valor, linha->prox);
			linha = linha->prox;
		}
		//Pula para o proximo valor
		printf("\n");
		coluna = coluna->prox;
	}
}

