/*Se desea leer y procesar información de precipitaciones del mes de enero. Por cada de los 31 días se tiene un número entero indicando los milímetros
llovidos, seguido de un guión medio (-) como delimitador. Escriba un programa que lea la información del archivo y derermine el día con mayor precipitación*/

#include <stdio.h>
#include <stdlib.h>


#define LONG 62

int main(){
    FILE *f;
    int linea[LONG];
 // Abrir el archivo
    f = fopen("precipitaciones.txt", "r");

    unsigned int imax, max=0;
    char valor;

    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
        }
    fscanf(f,"%c", &valor);// Lo hago con caracteres porque no puedo diferenciar el guion de un negativo
    while (!feof(f)){
        if (valor!='-'){
            printf("Dia %d\n", ((ftell(f)/2)+1));
            printf("%c\n",valor);
            if (valor>max){
                max=valor;
                imax=((ftell(f)/2)+1);
                }
            }
        fscanf(f,"%c", &valor);
        }
    fclose(f);
    printf("\nEl maximo valor fue %c en el dia numero %d", max, imax);
    return 0;
}
