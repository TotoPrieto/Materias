#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

int main (){
    FILE *f,*fi;
    char aux;
    char aux2[10];
    f=fopen("diccionario.txt", "r");


    if(f==NULL){
        printf("Archivo no encontrado.");
        return 1;
    }
    fi=fopen("copia.txt" ,"a+");

   /* aux=fgetc(f);
    while(!feof(f)){
        fputc(aux, fi);
        aux=fgetc(f);
    }
    */

    /*fgets(aux2, 10, f);
    while(!feof(f)){
        fputs(aux2, fi);
        fgets(aux2, 10, f);
    }
    */
    int cant=0;

    cant=fread(aux2, sizeof(char), 10, f);
    while(cant>0){
        fwrite(aux2, sizeof(char), cant, fi);
        cant=fread(aux2, sizeof(char), 1000, f);
    }


    fclose(f);
    fclose(fi);
    return 0;
}
