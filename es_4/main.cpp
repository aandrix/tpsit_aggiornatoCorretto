#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int *a,n;
    n = 5;
    a = (int*)malloc(n*sizeof(int));
    free(a);

}
