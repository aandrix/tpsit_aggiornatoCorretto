#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NMAX 5

typedef struct coda{
    int numero_ingresso;
    int valore;
    struct coda *next;
}Coda;

typedef struct lista{
    int numero_ingresso;
    int valore;
    struct lista *next;
}Lista;


int is_empty_l(Lista* head){
    if(head == NULL) return 1;
    else return 0;
}

int is_empty_c(Lista* head){
    if(head == NULL) return 1;
    else return 0;
}

void push(Lista **head, Lista *element){
    if(*head == NULL){
        *head = element;
        element->next = NULL;
    }else{
        element->next = *head;
        *head = element;
    }

}

Lista* pop(Lista **head){
    Lista *ret = *head;
    if(*head == NULL){
        return  NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}




void enqueue(Coda** head, Coda** tail, Coda* element){
    if(is_empty_l(*head))
        *head = element;
    else
        (*tail)->next = element;

    *tail = element;
    element->next = NULL;
}

Coda* dequeue(Coda** head, Coda** tail){
    Coda* ret = *head;

    if(is_empty_c(*head))
        return NULL;
    else
        *head = ret->next;

    if(*head == NULL)
        *tail = NULL;

    return ret;
}
//serve per generarmi un numero casuale compreso tra 10 e 1
int casuale(){
    int casuale;

    casuale = rand()%10+1;
    //per comodità non ho utilizzato delle costanti

    return casuale;
}

//stampa la coda ciclando con un ciclo while fino a quando
//il puntatore temp è uguale a null
void stampaCoda(Coda *head){
    Coda *temp = head;

    while(temp != NULL){

        printf("il numero di ingresso e' %d il valore e': %d\n", head->numero_ingresso, head->valore);
        temp = temp->next;
    }

}


//stampa la lista ciclando con un ciclo while fino a quando
//il puntatore temp è uguale a null
void stampaLista(Lista *head){
    Lista *temp = head;

    while(temp != NULL){

        printf("il numero di ingresso e' %d il valore e': %d\n", head->numero_ingresso, head->valore);
        temp = temp->next;
    }

}


void caricaCoda(Coda** head, Coda** tail){
    Coda *elemento;
    for(int k = 0; k< NMAX; k++){
        elemento = (Coda*)malloc(sizeof(Coda));
        elemento->numero_ingresso = k;

        elemento->valore = casuale();
        enqueue(&head, &tail, elemento);


    }

}

void caricaLista(Lista **head){
    //void push(Lista **head, Lista *element){
    Lista *elemento;
    for(int k=0 ; k<NMAX; k++){
        elemento = (Lista*)malloc(sizeof(Lista));
        elemento->numero_ingresso = k;
        elemento->valore = casuale();
        push(&head, elemento);
    }

}






int main(){
    Coda *coda;
    Lista *lista;
    //carico la coda
    caricaCoda(&coda, &coda);
    //stampo la codaù
    printf("stampo la coda\n");
    stampaCoda(coda);
    //carico la lista

    caricaLista(&lista);
    //stampo la lista
    printf("stampo la lista\n");
    stampaLista(lista);

}

