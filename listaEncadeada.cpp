#include<stdio.h>
#include<stdlib.h>

struct Linha {
	float valor;								
	struct Linha *prox;
};

struct Coluna {
	struct Linha;
	struct Coluna *prox;
};


Linha *imprimeLinha(Linha *lin){


	if (lin == NULL)
		return NULL;

	Linha *l = lin;

	while(l->prox != NULL){
		printf("%f", l->valor);
		l = l->prox;
	}

	return l;

}

void insereInicio(Linha *lin){

	Linha *primeiro = lin;
	
	for (int i=0; i<10; i++){

		struct Linha *novo = (struct Linha*) malloc(sizeof(struct Linha));
	
		if(novo == NULL){
			printf ("\nFALHA AO ALOCAR MEMORIA");
			exit(0);
		}

		novo->valor = i;
		novo->prox = primeiro;

		//printf("%f ", novo->valor);

		primeiro = novo;
		primeiro->prox = NULL;
	}
	
}


int main (int argc, char *argv[]){


	Linha *head = NULL; //aponta para o inicio da linha

	insereInicio(head);


	imprimeLinha(head);

	printf(" 1");
}
