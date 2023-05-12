#include <stdio.h>
#include <stdlib.h>

struct direccion{
    char calle[50] ;
    char ciudad[30];
    int codP;
    char pais[40];
};

struct alu{
    char apellido[50];
    char nombre[50];
    char legajo[8];
    float prom;
    struct direccion domicilio;
};
typedef  struct alu  alumno;

struct pun3D{
    float x;
    float y;
    float z;
};
typedef struct pun3D punto3D;

void CrearAlu(alumno*);
int Ejercicio3(){
    punto3D vec[4];
    printf("El tamanio es %d",sizeof(vec));



    alumno a1;
    CrearAlu(&a1);
    return 0;
}

void CrearAlu(alumno *a1){
    printf("Promedio ");
    scanf("%f",&a1->prom);
    printf("Legajo ");
    scanf("%s",&a1->legajo);
    printf("Nombre ");
    scanf("%s",&a1->nombre);
    printf("Apellido ");
    scanf("%s",&a1->apellido);
    printf("Codigo postal ");
    scanf("%d",&a1->domicilio.codP);
    printf("Pais ");
    scanf("%s",&a1->domicilio.pais);
    printf("Ciudad ");
    scanf("%s",&a1->domicilio.ciudad);
    printf("Calle ");
    scanf("%s",&a1->domicilio.calle);
}
