#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 1024
typedef char String[LUNG];

typedef struct{
    String data;
    String cognome;
    int importo;
}Alunno;

typedef struct{
    String cognome;
    int importoPagato;
}Pagamento;
int contaRighe(String nomeFile){
    String temp;
    int k=0;
    FILE *fp = fopen(nomeFile, "r");
    if(fp != NULL){
        while(fgets(temp, LUNG, fp)){k++;}
        fclose(fp);
        return k;
    }else{
        fclose(fp);
        return -1;
    }


}

void caricaDaFile(Alunno *a , String nomeFile, int dim){
    FILE *fp;
    int k;
    fp = fopen(nomeFile,"r"); //non controllo se il file ce perche l'ho gia controllato nella funzione conta righe
    String riga;
    k=0;
    while(k<dim){
        fgets(riga, LUNG, fp);
        *(a+k)->data = strtok(riga,";");
        *(a+k)->cognome = strtok(NULL ,";");
        (a+k)->importo = atoi(strtok(NULL ,";"));
        k++;
    }
    fclose(fp);
}
/*
 * scorro alunno per alunno e cerco in tutti i pagamenti effettuati,
 */
int cerca(char nome[],int posIn, Alunno *a, int dim){ //returna la posizione in cui trova la ricorrenza
    printf("%s", nome);
    bool tro = false;
    int k=posIn;
    printf("%s", nome);
    while(tro != true && k<dim) {
        if (strcmp((a + k)->cognome, nome) == 0) {
            tro=true;
        }
        k++;
    }
    return k;
}

int sommaImporti(Alunno *classe,Pagamento *lista, int nAl){
    int somma;
    String daCercare;
    int tro;
    int j=0;
    for(int k=0; k<nAl; k++){
        strcpy(daCercare, (classe+k)->cognome);
        printf("%s", daCercare);
        if(cerca(daCercare,k, classe, nAl)!=-1){
            tro = cerca((classe+k)->cognome,k, classe, nAl);

            *(lista+j)->cognome = *(classe+k)->cognome;
            (lista+j)->importoPagato = (int)((classe+k)->cognome + (classe+tro)->importo);
        }else{
            *(lista+j)->cognome = *(classe+k)->cognome;
            (lista+j)->importoPagato = (classe+k)->importo;
        }
        j++;
    }
    printf(" %d ", j);
    return j;

}

void stampa(Pagamento *pagamenti, int dim){
    for(int k=0; k<dim; k++){
        printf("cognonome-%s totale pagato-%f\n", (pagamenti+k)->cognome, (pagamenti+k)->importoPagato);
    }
}
/*
void stampaPagamenti(Alunno *classe, int dim){
    for(int k=0; k<dim; k++){
        printf("%s, %d")
    }

}
 */

int main(){
    Alunno *classe;
    Pagamento *lista;
    int newDim;
    String nomeFile = "../4AROB_GITA.csv";
    int dim = contaRighe(nomeFile);
    printf("\n%d\n", dim);
    if(dim > 0){
        lista = (Pagamento*)malloc(dim*sizeof(Pagamento));
        printf("a");
        classe = (Alunno*)malloc(dim*sizeof(Alunno));
        printf("b");
        caricaDaFile(classe, nomeFile, dim);
        printf("c");
        newDim = sommaImporti(classe, lista, dim);
        printf("d,%d",newDim);
        stampa(lista, newDim);
        }else{
        printf("il file potrebbere non esistere oppure essere vuoto");
    }
    free(classe);

}