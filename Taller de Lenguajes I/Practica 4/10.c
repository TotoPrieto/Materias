/* Escriba un programa que lea un número entero n y luego reserve memoria en forma dinámica para
un arreglo de n elementos double. Inicialice las posiciones del arreglo a partir de valores ingresados
por teclado y a continuación imprima el promedio de todos ellos.
Por último, libere la memoria reservada.
Nota: modularice la reserva de memoria, la inicialización, el cálculo del promedio y la liberación de
memoria.
 */

#include <stdio.h>
#include <stdlib.h>

void LiberarV(float*);
float ImprimirPromedio(float*, int);
void Leer(float*, int);
void Asignar(float* v, int n);
float* Inicializar(float* v, int n);

int main(){
    int n;
    printf("Ingresar numero a ingresar: ");
    scanf("%d",&n);
    float * v;
    v=Inicializar(&v, n);
    Asignar(v,n);
    printf("El promedio es: %f", ImprimirPromedio(v,n));
    LiberarV(v);
    Leer(v,n);
    return 0;
}


float * Inicializar(float* v,int n){
    v=(float*)calloc(n,sizeof(int));
    return v;
}

void Asignar(float * v, int n){
    int i;
    for (i=0;i<n;i++){
        printf("Valor a asignar %d: ",i);
        scanf("%f", &v[i]);
    }
}

void Leer(float * v,int n){
    int i;
    for (i=0;i<n;i++){
        printf("\nEl valor %d es: %f \n", i, v[i]);
    }
}

float ImprimirPromedio(float *v, int n){
    float prom=0;
    int i;
    for(i=0; i<n; i++){
        prom+=v[i];
    }
    return prom/n;
}

void LiberarV(float * v){
    int i;
    free(v);
}
