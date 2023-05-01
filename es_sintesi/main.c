#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 20
#define DIM 20
#define MAXRIGA 1024

/*
 -Creare un file .csv con COGNOME, NOME, NASCITA (annomesegiorno in formato INT)
-scorrere il file con la funzione FGETS e STRTOK
-stampare in ordine DECRESCENTE (dal più grande al più piccolo)
 utilizzando i puntatori e allocazione dinamica (MALLOC)
 */

typedef char String[LUNG];

typedef struct{
    String nome;
    String cognome;
    int dataNascita;

}Individuo;

int caricaDaFile(Individuo *vett, char nomeFile[]){
    FILE *fp;
    char riga[MAXRIGA];
    int k;
    fp = fopen(nomeFile,"r");
    if(fp != NULL) {
        printf("file aperto");
        k=0;
        while (fgets(riga, MAXRIGA, fp)) {
            strcpy((vett+k)->nome, strtok(riga, ","));
            strcpy((vett+k)->cognome, strtok(NULL, ","));
            (vett+k)->dataNascita = atoi(strtok(NULL,","));
            k++;
        }
    } else{
        printf("\nimpossibile aprire file\n");
        return -1;
    }
    fclose(fp);
    printf("\nfile aperto e letto\n");
    return k;

}

void printPersone(Individuo *vett, int dim){

        for(int k = 0; k < dim; k++){

            printf("\n%s %s %d\n", (vett+k)->nome, (vett+k)->cognome, (vett+k)->dataNascita);
        }
}

void ordina(Individuo *vett, int dim){
    int i,k;
    Individuo temp;
    for(i = 0; i<dim-1; i++) {
        for(k = 0; k<dim-1-i; k++) {
            if((vett+k)->dataNascita > (vett+k+1)->dataNascita) {
                temp = *(vett+k);
                *(vett+k) = *(vett+k+1);
                *(vett+k+1) = temp;
            }
        }
    }

}

int main(){
    Individuo *persone;
    int size = sizeof(Individuo);
    int dim;
    persone = (Individuo*)malloc(DIM*size);
    dim = caricaDaFile(persone, "../dati.csv");

    if(dim > 0){
        printPersone(persone, dim);
        printf("\n\tprocedo con l'odrinamento\n");
        ordina(persone, dim);
        printPersone(persone, dim);
    }else {
        printf("esecuzione fallita");
    }
    free(persone);

    return 0;
}
