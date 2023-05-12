#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct alu {
 char apellido[50];
 char nombre[50];
 char legajo[8];
};
typedef struct alu alumno;

void Inicilizar(alumno*);
int main(){
    int i;
    /*char palabra[20];
    char min[20];
    int minI=21;
    printf("Palabra: ");
    scanf("%s",&palabra);
    while (strcmp(palabra,"FIN")!=0){
        printf("Intente de nuevo\n");
        if(strlen(palabra)<minI){
            strcpy(min,palabra);
            minI=strlen(palabra);
        }
        printf("Palabra: ");
        scanf("%s",&palabra);
    }
    printf("El mas chico es %s",min);
*/
    alumno a[2];
    Inicializar(&a[0]);
    printf("Apellido y nombre: %s, %s | Legajo: %s",*a->apellido,a[0].nombre,a[0].legajo);
    return 0;
}

void Inicializar(alumno* a){
    printf("Apellido: ");
    scanf("%s",&a->apellido);
    printf("Nombre: ");
    scanf("%s",&a->nombre);
    printf("Legajo: ");
    scanf("%s",&a->legajo);
}
