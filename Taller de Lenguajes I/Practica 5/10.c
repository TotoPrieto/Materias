/*
a) escriba una función que permita actualizar el ranking de un jugador. Dicha función recibe como
parámetros nombre, apellido y nuevo ranking del jugador y retorna 1 si pudo realizar la
modificación y 0 en caso contrario.

b) escriba un programa que lea desde teclado el nombre y apellido de jugadores y sus nuevos
rankings hasta ingresar "ZZZ" y actualice el ranking de cada jugador o muestre un mensaje de
error en caso de no existir el jugador. Por último, imprima el contenido del archivo modificado,
para verificar que la actualización se haya aplicado correctamente
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#define CANT 3


typedef struct{
    char nombre[20];
    char apellido[20];
    int edad;
    int cantT;
    int rank;
    float fort;
} Tenis;


int Cambiar(FILE*, char[], char[], int,int);
int main(){
    FILE* f;

    f=fopen("Jugadores.dat","rb+");

    if(f==NULL){
        printf("No se pudo abrir el archivo");
        return 1;
    }

    char nomb[10], apell[10];
    int ranking;

    printf("Ingresar nombre del jugador: ");
    scanf("%s", &nomb);
    while (strcmp(nomb, "ZZZ")) {
        printf("Ingresar apellido del jugador: ");
        scanf("%s", &apell);
        printf("Ingresar nuevo ranking del jugador: ");
        scanf("%d", &ranking);
        rewind(f);
        if(Cambiar(f,nomb, apell, ranking,CANT)==1){
            printf("Modificacion realizada\n");
        }else{
            printf("No encontro al jugador\n");
        }

        printf("Ingresar nombre del jugador: ");
        scanf("%s", &nomb);
    }
    fseek(f, 0, SEEK_SET);
    Tenis tabla[3];
    int i;
    fread(tabla, sizeof(Tenis), 3, f);
    for(i=0;i<3;i++)
        printf("Imprimo jugador leido en binario: %s %s %d %d\n", tabla[i].nombre, tabla[i].apellido, tabla[i].rank, tabla[i].cantT);

    fclose(f);
    return 0;
}

int Cambiar(FILE * f, char nom[10], char ap[10], int rk, int dimL){
    Tenis t[dimL];
    int i=0,encontro=0;
  /*  while(!feof(f)){
        fread(&t, sizeof(Tenis), 1, f);
        if((strcmp((t.apellido),ap)==0)&&(strcmp((t.nombre),nom)==0)){
            t.rank=100;
            fwrite(&t, sizeof(Tenis), 1, f);
            printf("%d",t.rank);
            return 1;
        }
        fread(&t, sizeof(Tenis), 1, f);
    }*/

    fread(&t, sizeof(Tenis),dimL,f);
    while((i<dimL)&&(strcmp((t[i].apellido),ap))&&(strcmp((t[i].nombre),nom))){
        i++;
    }
    if(i<dimL){
        t[i].rank=rk;
        encontro=1;
        }
    rewind(f);
    if(encontro==1){
        fwrite(&t, sizeof(Tenis), dimL, f);
        return 1;
    }
    return 0;
}
