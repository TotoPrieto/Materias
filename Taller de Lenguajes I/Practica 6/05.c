#include <stdio.h>
#include <stdlib.h>
#define size 25

void imprimir(int * v, int size){ // No se puede poner constante define como parametros. Se tiene que cambiar el nombre de variable
    int i;
    for (i=0; i<size; i++){
        printf("v[%d]= %d\n", i, v[i]);
    }
}

int main(){
    int v[size];
    imprimir(v, size);
    return 0;
}
