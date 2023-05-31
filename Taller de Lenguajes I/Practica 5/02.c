#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    char linea[256];
    char c;
    int may=0,min=0;
    f= fopen("prueba.txt", "r");

    if(f ==NULL)
       printf("No hay archivo txt guardado.");
    else {
        //fprintf(stdout, "Archivo abierto\n");
       // fgets(linea,26 , f);
        c=fgetc(f);
        while(! feof(f)){
        //    fputs(linea, stdout);
            if((c>='A')&&(c<='Z'))
                may++;
            if((c>='a')&&(c<='z'))
                min++;
            c=fgetc(f);
            }
        fclose(f);

    }
    printf("El numero de mayusculas es de %d y de minusculas %d", may, min);

    return 0;
}