#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 50
#define NUM2 1024
#define LUNG 100
#define DIM 20000


/*
ESERCIZIO : 1;
TITOLO:Creare un programma in linguaggio C che legga il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui pu� essere comodo creare una funzione split
che dalla riga letta ritorni la struttura valorizzata.
*/

typedef char Stringa[NUM2];

typedef struct videogioco{
    int rank;
    char *nomeGioco;
    char *piattaforma;
    int anno;
    char *genere;
    char *publischer;
    float prezzoNA;
    float prezzoEU;
    float prezzoJP;
    float prezzoOTH;
    float prezzoGLO;
}Videogioco;

int main(){

    FILE *fp;
    Stringa riga;
    Videogioco gioco[DIM];
    Videogioco *a = gioco;
    int k=0;
    fp = fopen("vgsales.csv", "r");
    if(fp == NULL){
        printf("\nFILE INESISTENTE!");
        return 0;
    }else{
        printf("\nFILE APERTO!");
        while(fgets(riga, 1024, fp)){
            (*a).rank = atoi(strtok(riga,","));
            (*a).nomeGioco = strtok(NULL,",");
            (*a).piattaforma = strtok(NULL,",");
            (*a).anno = atoi(strtok(NULL,","));
            (*a).genere = strtok(NULL,",");
            (*a).publischer = strtok(NULL,",");
            (*a).prezzoNA = atof(strtok(NULL,","));
            (*a).prezzoEU = atof(strtok(NULL,","));
            (*a).prezzoJP = atof(strtok(NULL,","));
            (*a).prezzoOTH = atof(strtok(NULL,","));
            (*a).prezzoGLO = atof(strtok(NULL,","));
            printf("\n%d %c %c %d %c %c %f %f %f %f %f", (*a).rank, (*a).nomeGioco, (*a).piattaforma, (*a).anno, (*a).genere, (*a).publischer, (*a).prezzoNA, (*a).prezzoEU, (*a).prezzoJP, (*a).prezzoOTH, (*a).prezzoGLO);
            a++;
            k++;


        }

    }


    fclose(fp);


}
