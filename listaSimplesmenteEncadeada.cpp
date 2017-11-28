#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include "metodos.h"

int main ()
{
	Coluna coluna;
	coluna.linha = NULL;
	coluna.prox = NULL;
	
	int opt;

	printf("CONVERSOR CELCIUS -> FAHRENHEIT"
		"\n 1) Inserir temperatura na linha"
		"\n 2) Inserir nova linha"
		"\n 3) Converter para graus fahrenheit"
		"\n 0) Ajuda\n");

	while (true){
		printf("\n>>");
		scanf("%d", &opt);
		
		switch (opt){
			case 0:
				printf("Inserir as temperaturas em °C utilizando a opção 1, "
				"assim que todos os valores de uma linha forem inseridos "
				"utilizar a opção 2 para criá-la e iniciar uma nova linha com "
				"novos valores."
				"\nUtilizar a opção 3 para finalizar o programa e converter as unidades."
				"\nPressione qualquer outra tecla para terminar o programa.\n");
				break;
				
			case 1:	
				float n;
				printf("Informe o valor: ");
				scanf("%f", &n);
				insereLinha(&coluna, n);
				break;
			
			case 2:
				insereColuna (&coluna);
				printf("Nova linha criada!\n");
				break;
			
			case 3:
				printf("\nTemperaturas (°C): \n");
				imprimeCelsius (&coluna);
				printf("\n");
				printf("\nTemperaturas (°F): \n");
				converteFahrenheit (&coluna);
				break;
				
			/*
			case 4:
				printf("\nListar \n");
				Listar(&coluna);
				printf("\n");
				break;
				*/

			default: 
				liberarMemoria(&coluna);
				return 0;
		}
	}

	return 0;
}
