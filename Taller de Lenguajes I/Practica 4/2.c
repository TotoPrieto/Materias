#include <stdio.h>
#include <stdlib.h>


void f (int * p);

int main2(){
    int * ptr=NULL;
    f(ptr);
    if (ptr == NULL)
        printf("ptr es NULL\n");
    else
        printf("ptr no es NULL\n");
    return 0;
}

void f (int * p) {
    p = (int *) malloc(10*sizeof(int));
}

//No se puede hacerle malloc a una variable que tiene un valor
//Para eso se usaria el realloc
