/*
Escriba un programa que lea desde teclado números enteros de una cifra (del 0 al 9) y que cree dos
archivos, los cuales almacenen los números leídos. El primer archivo debe llamarse “numeros.txt” y
contener en formato texto todos los números leídos en forma consecutiva. El segundo archivo debe
llamarse “numeros.dat” y contener todos los números leídos en formato binario.
▪ Una vez ejecutado el programa, utilice un editor de texto (como por ejemplo: el Bloc de notas
en MS Windows, o Gedit en GNU/Linux) para abrir el archivo de texto y corroborar que la
información almacenada sea la correcta. Usando el mismo editor, intente abrir el archivo
binario. ¿Es posible visualizar los números? ¿Por qué cree que no es posible?
▪ Compare los tamaños que ocupan cada archivo. ¿Cuál es más grande? ¿En qué ocasiones
cree usted que sería mejor utilizar cada tipo de archivos?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>


int main (){

FILE *ft, *fb;
int i;
char j[1];


    ft=fopen("numeros.txt" ,"a+");
    fb=fopen("numeros.dat", "a+b");

    printf("Ingrese numeros de una cifra: ");
    scanf("%d", &i);
    while(i!=-1){
        j[0]=i;
        fprintf(ft, "%d", i);
        fwrite(j, sizeof(int),1, fb);
        scanf("%d", &i);
    }
    fclose(ft);
    fclose(fb);
    return 0;
}
