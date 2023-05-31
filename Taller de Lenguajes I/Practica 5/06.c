/*
Un archivo csv (Comma Separated Values) contiene información separada por comas. Cada renglón
(fila) contiene un registro de información. Cada columna contiene un campo particular de
información. La primera fila es especial ya que contiene los nombres de los campos.
Se desea obtener información a partir del archivo llamado vinos.csv (el cual se encuentra en la
Sección “Ing. Gral. y Contenidos” del curso de la cátedra en WebUNLP). El programa debe generar
un archivo de texto con un resumen que indique el valor máximo, mínimo y promedio para cada
uno de los campos del archivo. Este archivo debe llamarse reporte_vinos.txt y debe guardarse en la
misma ruta que el archivo vinos.csv

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define CATEGORIAS 8
#define LONG 25
#define NumInicio 300
enum {PROM, MIN, MAX};

void Imprimir(FILE*);
void Guardar(FILE *, char nombres[NumInicio], float res[][CATEGORIAS]);
void Promedio(float[][CATEGORIAS],int);
void Calcular(float[][CATEGORIAS],FILE*, char[NumInicio]);
int main(){
    FILE* f,resul;
    float res[3][CATEGORIAS]={{0},{FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX,FLT_MAX},{FLT_MIN}};
    char nombres [NumInicio];

    f=fopen("vinos.csv", "r");
    if(f==NULL){
        printf("Error al abrir.");
        return 1;
        }

    Calcular(res, f, nombres);

    fclose(f);
    f=fopen("reporte_vinos.txt", "a+");
    Guardar(f, nombres, res);
    fclose(f);
    return 0;
}

void Guardar(FILE *f, char nombres[NumInicio], float res[][CATEGORIAS]){
    fprintf(f, "%s","Atributo\t\t");
    fputs(nombres, f);
    int i,j;
    for(j=PROM;j<=MAX;j++){
        switch (j){
        case PROM:fprintf(f, "%s","\nPromedio \t\t");
            break;
        case MIN:fprintf(f, "%s","\nMinimo \t\t");
            break;
        case MAX:fprintf(f, "%s","\nMaximo \t\t");
            break;
        }
        for (i=0;i<CATEGORIAS;i++){
            fprintf(f,"%f\t",res[j][i]);
        }
    }
}

void Calcular(float res[][CATEGORIAS], FILE *f,char nombres[NumInicio]){
    int i,j, cant=0;
    char  basura[10];
    float aux[CATEGORIAS];
    fgets(nombres,NumInicio, f);
    while (!feof(f)){
        fscanf(f,"%f;",&aux[0]);
        for(i=1;i<CATEGORIAS;i++)
            fscanf(f,"%f;", &aux[i]);
        fscanf(f,"%s",&basura);

        for(j=0;j<CATEGORIAS;j++){

            res[PROM][j]+=aux[j];

            if(aux[j]<res[MIN][j])
                res[MIN][j]=aux[j];

            if(aux[j]>res[MAX][j])
                res[MAX][j]=aux[j];

        }
        cant++;
        }

    Promedio(res,cant);

}


void Promedio(float res[][CATEGORIAS],int cant){
    int i;
    for(i=0;i<CATEGORIAS;i++){
        res[PROM][i]=res[PROM][i]/(float)cant;
    }
}

