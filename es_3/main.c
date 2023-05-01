#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 50
#define NUM2 1024
#define LUNG 100
#define DIM 16598

/*

 GIORDANO ANDREA

Creare un programma in linguaggio C che legga
il file vgsales.csv e lo importi in un array di strutture.
Ogni riga contiene i campi separati da virgole, per cui può
essere comodo creare una funzione split che dalla riga letta
ritorni la struttura valorizzata.
*/

typedef char Stringa[NUM2];

typedef struct videogioco {

    int rank;
    char *nomeGioco;
    char *piattaforma;
    int anno;
    char *genere;
    char *publisher;
    float prezzoNA;
    float prezzoEU;
    float prezzoJP;
    float prezzoOTH;
    float prezzoGLO;

} Videogioco;

int main(){

    FILE *fp;
    Stringa riga;
    Videogioco gioco[DIM];
    Videogioco *a;// = gioco;
    //*(a + 1);
    a = (Videogioco*)malloc(16598 * sizeof(Videogioco));


    int k;

    k = 0;
    fp = fopen("vgsales.csv", "r");

    if(fp == NULL) {

        printf("Il file non esiste.");
        return 0;

    } else {

        k = 0;



        printf("\nFILE APERTO!\n\n");
        fgets(riga, 1024, fp);
        while(!feof(fp)){
            fgets(riga, 1024, fp);
            (*a).rank = atoi(strtok(riga,","));
            (*a).nomeGioco = strtok(NULL,",");
            (*a).piattaforma = strtok(NULL,",");
            (*a).anno = atoi(strtok(NULL,","));
            (*a).genere = strtok(NULL,",");
            (*a).publisher = strtok(NULL,",");
            (*a).prezzoNA = atof(strtok(NULL,","));
            (*a).prezzoEU = atof(strtok(NULL,","));
            (*a).prezzoJP = atof(strtok(NULL,","));
            (*a).prezzoOTH = atof(strtok(NULL,","));
            (*a).prezzoGLO = atof(strtok(NULL,","));


            printf("%d,%s,%s,%d,%s,%s,%.2f,%.2f,%.2f,%.2f,%.2f\n\n", (*a).rank, (*a).nomeGioco, (*a).piattaforma, (*a).anno, (*a).genere, (*a).publisher, (*a).prezzoNA, (*a).prezzoEU, (*a).prezzoJP, (*a).prezzoOTH, (*a).prezzoGLO);

            k ++;

            //printf("%d\t", k);

        }

    }

    fclose(fp);

    return 0;

}