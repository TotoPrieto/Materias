#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SQUAREOF(x) x*x
int main() {
    int xin=3;
    printf("\nxin=%i",xin);
    printf("\nSQUAREOF(xin)=%i", SQUAREOF(xin));
    //Seris xin+4*xin+4 --> xin+(4*xin)+4 == 3+12+4
    printf("\nSQUAREOF(xin+4)=%i MAL HECHO", SQUAREOF(xin+4));
    //xin+xin*xin+xin --> xin+(xin*xin)+xin == 3+9+3
    printf("\nSQUAREOF(xin+xin)=%i MAL HECHO", SQUAREOF(xin+xin));
    printf("\nSQUAREOF(xin+4)=%i BIEN HECHO", SQUAREOF((xin+4)));
    //xin+xin*xin+xin --> xin+(xin*xin)+xin == 3+9+3
    printf("\nSQUAREOF(xin+xin)=%i BIEN HECHO", SQUAREOF((xin+xin)));

    //Se usan parentesis para arreglar el problema
}
