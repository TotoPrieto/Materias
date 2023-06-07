#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "imath.h"
#define nPares(x,y)    (!(x%2))+(!(y%2))

struct destino{
    int codProv;
    int codLoc;
    char nomLoc[30];
    int nHab;
};

struct lista{
    struct destino dato;
    struct lista * ptr;
};


int main(){
    FILE *ft, *fb;
    ft=fopen("Habitantes.txt","r");
    struct lista *Pila=NULL, *aux, *act, *ant;

    do{
        aux=(struct lista*) malloc(sizeof(struct lista));
        fscanf(ft, "%d ",&aux->dato.codProv);
        fscanf(ft, "%d ",&aux->dato.codLoc);
        fscanf(ft, "%s ",aux->dato.nomLoc);
        fscanf(ft, "%d",&aux->dato.nHab);
        act=Pila;
        while(act!=NULL){
            ant=act;
            act=act->ptr;
        }
        if(Pila ==NULL){
            aux->ptr=NULL;
            Pila=aux;
        }else{
            aux->ptr=act;
            ant->ptr=aux;
        }

    } while (!feof(ft));

    fclose(ft);
    fb=fopen("Habitantes.dat","wb");

    while(Pila!= NULL){
        fwrite(&Pila->dato, sizeof(struct destino), 1, fb);
        Pila=Pila->ptr;
    }
    fclose(fb);


    int cant=0;
    char* nombre;
    fb=fopen("Habitantes.dat", "rb");
    struct destino destAct, max;
    max.nHab=0;
    do{
        fread(&destAct, sizeof(struct destino), 1, fb);
        if(destAct.nHab>max.nHab){
            max=destAct;
            }
         printf("%d %s \n",destAct.nHab,destAct.nomLoc);


    }while(!feof(fb));
    printf("La ciudad con mas habitantes es %s con %d de poblacion ", max.nomLoc, max.nHab);
    return 0;
} 


//&string
//->
