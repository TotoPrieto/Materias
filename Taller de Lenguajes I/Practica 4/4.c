/* Escriba un programa que lea un número entero n desde teclado y luego reserve memoria en forma
dinámica para un arreglo de n float. Inicialícelo con valores ingresados por teclado y a continuación
calcule e imprima el promedio de todos ellos. Por último, libere la memoria reservada dinámicamente.
Nota: Modularice la reserva de memoria, la inicialización y el cálculo del promedio.*/
#include <stdio.h>
#include <stdlib.h>

float Prom(float *,int);
void Asignar(float *, int);
void Inicializar(float *, int);

int main(){
    int n;
    printf("Ingresar numero de elementos: ");
    float* v;
    scanf("%d",&n);
    Inicializar(&v,n);
    Asignar(v,n);
    printf("\nEl promedio es %f",Prom(v,n));
    return 0;
}

void Inicializar(float* v,int n){
    v=(float*)calloc(n,sizeof(int));
}

void Asignar(float* v,int n){
    int i;
    for (i=0;i<n;i++){
        printf("Valor a asignar: ");
        scanf("%f", &v[i]);
    }
}

float Prom(float* v,int n){
    int i;
    float pm=0;
    for (i=0;i<n;i++){
       pm+=v[i];
    }
    pm= pm/(float)n;
    return pm;
}

