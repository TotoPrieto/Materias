/*
Escriba un programa que lea información de 20 jugadores de tenis. De cada jugador se lee nombre y
apellido, edad, cantidad de títulos, ranking actual y fortuna acumulada. Defina una estructura de
datos adecuada para la información y almacene la misma en un archivo binario. Finalizada la
lectura, procese los datos almacenados en el archivo e informe:
a) Nombre y apellido del jugador con mejor ranking.
b) Nombre y apellido del jugador que más títulos ha ganado.
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

void InformarMejRank(FILE *, int);
void CargarDatos(FILE *, Tenis[], int);
void leerTenis(Tenis[], int);
int main(){
    FILE* fb;
    Tenis t[CANT];
    leerTenis(t, CANT);

    fb=fopen("Jugadores.dat","wb+");

    CargarDatos(fb, t, CANT);
    rewind(fb);
    InformarMejRank(fb,CANT);




    fclose(fb);
    return 0;
}



void leerTenis(Tenis v[], int diml){
    for(int i=0; i<diml; i++){
        printf("Nombre: ");
        scanf("%s", v[i].nombre);

        printf("Apellido: ");
        scanf("%s", v[i].apellido);

        printf("Edad: ");
        scanf("%d", &v[i].edad);

        printf("Cantidad de titulos: ");
        scanf("%d", &v[i].cantT);
        printf("Ranking mundial: ");
        scanf("%d", &v[i].rank);

        printf("Fortuna:");
        scanf("%f", &v[i].fort);
    }
}

void CargarDatos(FILE * fb, Tenis t[], int dimL){
    int i;
    for(i=0; i<dimL; i++){
        fwrite(&t[i], sizeof(Tenis), 1, fb);
    }
}

void InformarMejRank(FILE * fb, int dimL){
    Tenis act,mayRank, mayTits;
    int mayR=9999, mayT=0;
    char nom[20], ape[20];
    fread(&act, sizeof(Tenis), 1, fb);
    while(!feof(fb)){
        if((act.rank)<mayR){
            mayR=act.rank;
            mayRank=act;
        }
        if((act.cantT)>mayT){
            mayT=act.rank;
            mayTits=act;

        }
        fread(&act, sizeof(Tenis), 1, fb);
    }
    printf("El tenista con mayor ranking es %s, %s.\n", mayRank.apellido, mayRank.nombre);
    printf("El tenista con mayor cantidad de titulos es %s, %s.\n", mayTits.apellido, mayTits.nombre);

}
