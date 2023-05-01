#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *s;
    char string[10];
    *s = string;
    *(s+3)='r' ;
    printf("%c", *(s+3));

}
