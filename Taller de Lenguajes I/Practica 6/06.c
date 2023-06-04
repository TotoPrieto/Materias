/*
Realice un programa que defina una macro AREA_CIRCULO(r) que permita calcular el área de un círculo
para un radio r. El cuerpo del programa debe generar aleatoriamente 10 valores diferentes que
representan radios e imprimir el área correspondiente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.14159265359
#define AREA_CIRCULO(r) PI*r*r
#define CANT 10

//void calcular(int * v, int size){ // No se puede poner constante define como parametros. Se tiene que cambiar el nombre de variable



int main(){
    int i, r[CANT];
    srand(time(NULL));
    for(i=0; i<CANT; i++){
        r[i]=rand()%50;
        printf("\nr[%d]== %d. Su area es %f", i, r[i], (float)AREA_CIRCULO(r[i]));
    }
    return 0;
}
