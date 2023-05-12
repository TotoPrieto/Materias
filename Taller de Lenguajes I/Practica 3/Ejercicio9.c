#include <stdio.h>
#include <stdlib.h>

//ej 8

typedef enum { DOMINGO, LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO } dia;

void Leer1(dia);
void Leer2(dia);
int main(){
    dia hoy=LUNES;
    dia maniana=MARTES;
    Leer1(hoy);
    Leer2(maniana);

    return 0;
}

void Leer1(dia i){
    switch (i){
    case DOMINGO: printf("Domingo");
    break;
    case LUNES: printf("Lunes");
    break;
    case MARTES: printf("Martes");
    break;
    case MIERCOLES: printf("Miercoles");
    break;
    case JUEVES: printf("Jueves");
    break;
    case VIERNES: printf("Viernes");
    break;
    case SABADO: printf("Sabado");
    break;
    default: printf("Le erraste al dia boludo");
    break;
    }
}

void Leer2(dia i){
    char *dias[]={"Domingo","Lunes","Martes","Miercoles","Jueves","Viernes","Sabado"};
    if(i>DOMINGO && i<SABADO){
            printf("\n%s",dias[i]);
    }else{
        printf("\nLa pecheaste otra vez");
    }




}
