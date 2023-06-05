/*
Realice un programa que genere un vector de 1000 enteros al azar y utilice una función para localizar un
elemento. Se pide:
a) Implementar la función de búsqueda que, dado un entero, retorne la posición donde se encuentra.
En caso de no existir el número retorne -1.
b) Modificar a) para agregar información de depuración que permita imprimir en consola la cantidad
de veces que se debió acceder al arreglo para encontrar (o no) el elemento en cada llamado a la
función. Utilice las directivas del procesador para activar/desactivar la depuración e imprimir/no
imprimir la información en la consola.
c) Verifique el tamaño del programa compilando con la depuración y sin la depuración. Explique
porque difieren.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CANT 1000
#define IMPRIMIR 0

int Buscar(int[],int, int);
void Asignar(int[], int);
int main(){
    int vector[CANT];
    Asignar(&vector, CANT);
    int n=Buscar(vector, CANT, 10);
    #if IMPRIMIR==0
    if(n!=-1)
        printf("\nSe tardo en encontrar el dato %d ciclos", n+1);
    else
        printf("\nNo se econtro el valor");
    #endif // IMPRIMIR
    return 0;
}

void Asignar(int vec[], int dimF){
    srand(time(NULL));
    int i;
    for(i=0;i<dimF;i++){
        vec[i]=rand()%100;
        printf("vec[%d]--> %d\n",i, vec[i]);
    }
}

int Buscar(int vec[],int dimF, int x){
    int i=0,resultado=-1;
    while(resultado==-1 && i<dimF){
        if(vec[i]==x){
            resultado=i;
        }
        i++;
    }

    return resultado;
}