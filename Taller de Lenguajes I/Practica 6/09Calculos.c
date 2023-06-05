#include "imath.h"


int potencia(int x, int y){
    int i, resultado=0;
    for(i=1;i<=y;i++){
        resultado+=x;
    }
    return resultado;
}

int cuadrado(int x){
    return (x*x);
}

int cubo(int x){
    return (x*x*x);
}

int absoluto(int i){
    if(i<0)
        return -i;
    else
        return i;
}

int factorial(int i){
    if (i == 1) return 1;
        return i*(factorial(i-1));
}

int sumatoria (int i) {
    int resultado=0,j;
    for(j=1;j<=i;i++){
        resultado+=j;
    }
    return resultado;
}

int multiplo (int x, int y){
    return(x % y)==0 ? 1 : 0;
}

int divisor (int x, int y) {
    return (y % x)==0 ? 1 : 0;
}

int par (int i) {
    return !(i % 2);
}
int impar (int i) {
    return i%2;
}
