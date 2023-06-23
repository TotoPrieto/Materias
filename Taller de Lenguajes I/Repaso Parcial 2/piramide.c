#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int** CrearPiramide();
void Asignar(int**);
void Leer(int**);
void Liberar(int**);

int main(){
    int** matriz=CrearPiramide();

    Asignar(matriz);

    Leer(matriz);

    Liberar(matriz);

    return 0;
}

int **CrearPiramide(){
    int **matriz=(int**)calloc(9,sizeof(int*));
    int i;
    for(i=0;i<9;i++){
        matriz[i]=(int*)calloc((i+1),sizeof(int));
    }
    return matriz;
}


void Asignar(int** matriz){
    int i,j;
    srand(time(NULL));
    for(i=0; i<9;i++){
        for(j=0;j<(i+1);j++){
            matriz[i][j]=1+rand()%8;
            }
        }
    }


void Leer(int ** matriz){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<(i+1);j++){
            printf("%d", matriz[i][j]);
            }
            printf("\n");
        }

    }


void Liberar(int** matriz){
    int i;
    for (i=0;i<9;i++){
        free(matriz[i]);
    }
    free(matriz);
}
