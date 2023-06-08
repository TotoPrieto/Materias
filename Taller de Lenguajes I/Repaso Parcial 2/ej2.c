#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Defina el tipo de dato Pirámide que permita representar de manera dinámica y eficiente una pirámide de
enteros con n elementos en su base, n-1 en el siguiente nivel, y así sucesivamente hasta llegar al último nivel con
1 elemento.
b) Dados los siguientes prototipos, implementar una función que permita reservar y liberar una pirámide de n
elementos de base.
*/

#define NUM 12
typedef int ** Piramide;

void liberar_piramide(Piramide p, int n);
void Leer(Piramide matriz, int F, int C);
Piramide crear_piramide(int);

int main(){

    Piramide matriz=crear_piramide(NUM);

    Leer(matriz, NUM, NUM);

    liberar_piramide(matriz, NUM);

    Leer(matriz, NUM, NUM);
}





Piramide crear_piramide(int n){
    Piramide matriz;
    matriz=(int**)calloc(n, sizeof(int*));
    int i,j,k=0;
    for (i=0; i<n; i++){
        matriz[i]=(int*)calloc(n,sizeof(int));
    }
    srand(time(NULL));
    for(i=0;i<n;i++){
        for(j=0;j<=k;j++){
            matriz[i][j]=1+rand()%8;
        }
        k++;
    }
    return matriz;

}


void Leer(Piramide matriz, int F, int C){
     int i,j;
     for(i=0;i<F;i++){
        for(j=0;j<C;j++){
           if(matriz[i][j]!=0){
            printf("%d  ", matriz[i][j]);
           }
        }
        printf("\n");
    }
}

void liberar_piramide(Piramide matriz, int n){
    int i;
    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
