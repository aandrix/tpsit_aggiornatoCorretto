#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui può essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata.*/

#define LUNG 20
#define NGIOCHI 20000

typedef char stringa[LUNG];

typedef struct{
    int rank;
    stringa name;
}videogioco;

int main()
{
    videogioco v[NGIOCHI];

    FILE *fp;
    fp = fopen(".\\..\\vgsales.csv", "r");


    //controlla se file esiste
    if(fp == NULL){
        printf("il file non esiste.");
        return 0;
    }

    //lettura file
    int k = 0;
    while (k < NGIOCHI && fscanf("%d %s", v->rank, v->name) != EOF){

    }

    //stampa

    printf("hey");



    fclose(fp);
    return 1;
}
