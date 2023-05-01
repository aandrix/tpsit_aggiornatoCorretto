#include <stdio.h>
#include <stdlib.h>
#incude <string.h>

/*
-Creare un file .csv con COGNOME, NOME, NASCITA (annomesegiorno in formato INT)
-scorrere il file con la funzione FGETS e STRTOK
-stampare in ordine DECRESCENTE (dal più grande al più piccolo)
 utilizzando i puntatori e allocazione dinamica (MALLOC)
 */

typedef struct{
    char cognome[LUNG];
    char nome[LUNG];
    int data_nascita; //gg mm aa
}Persona;

void caricaDaFile(){
    FILE* fp;
    fp = fopen(nomeFile,"r");
    if(fp != NULL){
        printf("file aperto");
        while(fscanf)
    }else{
        print("apertura del file fallita");
    }
}

int main(){
    dimElmem = syzeof(Persona);

}<