/*Escriba un programa que lea un número entero n desde teclado y luego reserve memoria en forma
dinámica para un arreglo de n enteros. Inicialícelo con valores aleatorios y a continuación calcule e
imprima el máximo número almacenado. Por último, libere la memoria reservada dinámicamente.
Nota: Modularice la reserva de memoria, la inicialización y el cálculo del máximo.*/

#include <stdio.h>
#include <stdlib.h>

int Max(int *,int);
void Asignar(int*, int);
void Inicializar(int*, int);

int main(){
    int n;
    printf("Ingresar numero de elementos: ");
    int* v;
    scanf("%d",&n);
    Inicializar(&v,n);
    Asignar(v,n);
    printf("\nEl maximo es %d",Max(v,n));
    return 0;
}

void Inicializar(int* v,int n){
    v=(int*)calloc(n,sizeof(int));
}

void Asignar(int* v,int n){
    int i;
    for (i=0;i<n;i++){
        v[i]=(int)rand()%100;
        printf("-%d",v[i]);
    }
}

int Max(int* v,int n){
    int i;
    int mx=0;
    for (i=0;i<n;i++){
       if(mx<v[i])
            mx=v[i];
    }
    return mx;
}
