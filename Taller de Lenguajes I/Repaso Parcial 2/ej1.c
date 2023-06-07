
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    struct lista *Pila=NULL, *aux;

    do{
        aux=(struct lista*) malloc(sizeof(struct lista));
        fscanf(ft, "%d ",&aux->dato.codProv);
        fscanf(ft, "%d ",&aux->dato.codLoc);
        fscanf(ft, "%s ",&aux->dato.nomLoc);
        fscanf(ft, "%d",&aux->dato.nHab);
      //  fscanf(ft, "%s",&basura);
        aux->ptr=Pila;
        Pila=aux;
    } while (!feof(ft));
    fclose(ft);
    fb=fopen("Habitantes.dat","wb");
    while(Pila!= NULL){
        fwrite(&Pila->dato, sizeof(struct destino), 1, fb);
        Pila=Pila->ptr;
    }
    fclose(fb);
    return 0;
}
