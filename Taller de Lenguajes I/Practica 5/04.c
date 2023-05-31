/*Escriba un programa que procese la información del archivo e informe el monto total apostado.*/

#include <stdio.h>
#include <stdlib.h>


#define LONG 100

int main(){
    FILE *f;
    int linea[LONG];
    int cod;
    float valor, tot=0;

 // Abrir el archivo
    f = fopen("apuestas.txt", "r");


    if (f == NULL){
        printf ("\nError al abrir archivo fuente\n");
        return 1;
        }
    fscanf(f,"%d|%f;", &cod,&valor);
    while (!feof(f)){
        printf("%f\n",valor);
        tot+=valor;
        fscanf(f,"%d|%f;", &cod,&valor);
        }



    printf("\nEl valor total de apuestas fue de %f", tot);
    fclose(f);
    return 0;
}
