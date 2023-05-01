#include <stdio.h>
#include <stdlib.h>

int main(){
    int dim = 10;
    int vet[dim];

    int *pi=vet;
    for(int k=0; k<dim ; k++){
        vet[k]=k;
    }
    *(pi+3) = 23;
    for(int k=0; k<dim; k++){
        printf("\t%d", *(pi+k));
    }
}
