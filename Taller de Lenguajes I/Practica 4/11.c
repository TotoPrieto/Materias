/*Escriba un programa que lea desde teclado dos valores enteros n y m, y luego reserve memoria en
forma dinámica para una matriz de enteros de n filas por m columnas. Inicialice la matriz creada con
valores ingresados por teclado. Una vez inicializada, imprima las posiciones de todos aquellos valores
múltiplos de 3. Por último, libere la memoria reservada.
Nota: modularice la reserva de memoria, la inicialización, la impresión de las posiciones con valores
múltiplo de 3 y la liberación de memoria.
*/
#include <stdio.h>
#include <stdlib.h>


void ImprimirMultiplosTres(int ** mat, int n, int m);
void LiberarM(int **, int);
void Asignar(int **, int, int);
int ** Inicializar(int, int);
int main(){
    int n,m;
    printf("Ingresar numero filas: ");
    scanf("%d",&n);
    printf("Ingresar numero columnas: ");
    scanf("%d",&m);
    int **mat=Inicializar(n,m);
    Asignar(mat,n,m);
    ImprimirMultiplosTres(mat, n, m);
    LiberarM(mat, n);
    Leer(mat,n,m);//corroboro que se borro
    return 0;
}

int ** Inicializar(int f, int c){
    int i;
    int **mat=(int**) calloc(f,sizeof(int));
    for (i=0; i<c; i++){
        mat[i]=calloc(c,sizeof(int));
    }
    return mat;
}

void Asignar(int ** mat, int n, int m){
    int i,j;
    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            printf("Valor de %d,%d: ", i,j);
            scanf("%d", &mat[i][j]);
        }
    }

}
void Leer(int **mat ,int n, int m){
    int i,j;
    for (i=0;i<n;i++){
        for(j=0; j<m; j++){
            printf("\nEl valor %d,%d es: %d \n", i,j, mat[i][j]);
        }
    }
}

void LiberarM(int ** mat, int n){
    int i;
    for (i=0;i<n;i++){
        free(mat[i]);
        }
    free(mat);
}

void ImprimirMultiplosTres(int ** mat, int n, int m){
   int i,j;
    for (i=0;i<n;i++){
        for(j=0; j<m; j++){
            if(mat[i][j]%3==0){
                printf("\nPosicion %d,%d es multiplo de 3", i,j);
            }
        }
    }

}