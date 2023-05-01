#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 20

typedef struct node{
	char nome[LUNG];
	struct node *next;
}Node;

int main(){
	Node* lista = (Node*)malloc(sizeof(Node));
	Node* temp = (Node*)malloc(sizeof(Node));
	printf("Inserisci un nome: ");
	gets(lista->nome);
	lista->next = NULL;
	printf("Nome1: %s",lista->nome);

	printf("\nInserisci un nome: ");
	gets(temp->nome);
	printf("Nome2: %s",temp->nome);
	temp->next = NULL;

	lista->next = temp;
	printf("\nInserisci un nome: ");
	gets(temp->nome);
	printf("Nome3: %s\n",temp->next->nome);
	temp->next = NULL;

	lista->next->next = temp;
	printf("\nNome1:%s\nNome2:%s\nNome3:%s",lista->nome,lista->next->nome,lista->next->next->nome);
	free(lista);
	free(temp);
	return 0;
}