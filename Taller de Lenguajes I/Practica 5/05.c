/* Escriba un programa que permita a un usuario consultar si un conjunto de palabras existe o no en
un diccionario. El usuario ingresa de a una palabra y la consulta finaliza cuando ingresa la palabra
“ZZZ”. Para cada palabra ingresada se debe informar si la misma pertenece o no al diccionario.
El diccionario consiste en un archivo de texto y las palabras se encuentran ordenadas en forma
ascendente (una por línea). Se desea generar una estructura de datos dinámica (memoria RAM) en
la cual se almacenen las palabras de todo el diccionario. Luego, verifique la pertenencia de las
palabras ingresadas por el usuario utilizando dicha estructura en lugar del archivo.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG 25

struct nodo{
        char dato[LONG];
        struct nodo * ptr;
    };
typedef struct nodo nodo;
typedef nodo* lista;

void inicializarLista(lista*);
void Leer(struct nodo*);
lista agregarInicio(lista*, char[]);
int main(){
    lista l;
    inicializarLista(&l);
    FILE *f;
    char linea[LONG];
    char* buscar[LONG];

    f = fopen("diccionario.txt", "r");


    if (f == NULL){
        printf ("Error\n");
        return 1;
    }
   fscanf(f, "%s", &linea);
   while (!feof(f)) {//Si un error de entrada ocurre antes de cualquier conversión, la función fscanf retorna EOf
        l=agregarInicio(l, linea);
        fscanf(f, "%s", &linea);
        }
    fclose(f);
    Leer(l);
    printf("Ingresar palabra a buscar: ");
    scanf("%s",&buscar);
    while(strcmp(buscar, "ZZZ")){
        lista aux=l;
        while((aux!=NULL)&&(strcmp(buscar, aux->dato)!=0)){
            aux=aux->ptr;
            }
        if (aux==NULL){
            printf("%s no pertenece al diccionario.\n",buscar);
        }else{
                printf("%s pertenece al diccionario.\n",buscar);
        }
        printf("Ingresar palabra a buscar: ");
        scanf("%s",&buscar);
        }
    printf("Chau");
    return 0;
}



void inicializarLista(lista* l){
    (*l)=NULL;
}

void Leer(struct nodo* Pila){
    lista aux=Pila;
    while(aux!=NULL){
        printf("%s- ",(*aux).dato);
        aux=aux->ptr;
    }
    printf("\n");
}

lista agregarInicio(lista* l, char dato[LONG]){
    lista act;
    act=(lista)malloc(sizeof(nodo));//reservo mem
    strcpy(act->dato,dato);//destino, fuente
    (*act).ptr=l;
    l=act;

}

