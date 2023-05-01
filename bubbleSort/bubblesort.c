#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIM 10

/*
 * utilizzo di un bubble-sort senza le
 * parentesi quadre
 */

bool caricaDafile(int *a, int dim){
    bool aperto;
    FILE *fp;
    fp = fopen("vettore.txt","r");
    if(fp != NULL){
        for(int k=0; k<dim; k++){
            fscanf(fp,"%d ", a+k);
        }
        aperto = true;
    }else{
        printf("non è stato possibile aprire il file");
        aperto = false;
    }
    fclose(fp);
    return aperto;

}

void bubbleSort(int *a, int dim){
    int i,k;
    int temp;
    for(i = 0; i<dim-1; i++) {
        for(k = 0; k<dim-1-i; k++) {
            if(*(a+k) > *(a+k+1)) {
                temp = *(a+k);
                *(a+k) = *(a+k+1);
                *(a+k+1) = temp;
            }
        }
    }
}

void stampaVett(int *a, int dim){
    for(int k=0; k<dim; k++){
        printf("%d ", *(a+k));
    }
}

int main(){
    int vett[DIM];
    int dim = DIM;
    int *a = vett;
    if(!caricaDafile(a, dim)){
        return 0;
    }else{
        bubbleSort(a, dim);
        printf("\n");
        stampaVett(a, dim);

    }

}
