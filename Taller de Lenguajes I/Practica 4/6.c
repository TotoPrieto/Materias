/*6. Defina la estructura de una lista enlazada de enteros. Implemente las siguientes funciones:
   X a. Inicializar la lista.
   X b. Eliminar todos los elementos de la lista.
   X c. Agregar un elemento al principio de la lista.
   X d. Agregar un elemento al final de la lista.
   X e. Calcular la cantidad de elementos de la lista.
   X f. Imprimir todos los elementos separados por coma.
*/
#include <stdio.h>
#include <stdlib.h>


struct nodo{
        int dato;
        struct nodo * ptr;
    };
struct nodo *Pila=NULL;

int CalcularNodos(struct nodo*);

struct nodo*  AgregarFinal(struct nodo*);

struct nodo* AgregarInicio(struct nodo*);

struct nodo * EliminarTodo(struct nodo*);

void Leer(struct nodo *);

struct nodo* Inicializar(struct nodo *);

int main(){
    Pila=Inicializar(Pila);
    Pila=EliminarTodo(Pila);
    Pila=AgregarInicio(Pila);
    Pila= AgregarFinal(Pila);
    printf("\n\n_");
    Leer(Pila);
    printf("La cantidad de nodos actuales es: %d",CalcularNodos(Pila));
    return 0;
}

struct nodo* Inicializar(struct nodo *Pila){
    int n;
    struct nodo * aux;

    printf("Ingrese un valor para la lista: ");
    scanf("%d", &n);
    while(n!=-1){
        aux= (struct nodo *) malloc(sizeof (struct nodo));
        aux->dato = n;
        (*aux).ptr=Pila;
        Pila=aux;
        printf("Ingrese otro valor para la lista: ");
        scanf("%d", &n);
    }
    return Pila;
}
void Leer(struct nodo* Pila){
    struct nodo * aux=Pila;
    while(aux != NULL){
        printf("%d - ",(*aux).dato);
        aux=aux->ptr;
    }
}

struct nodo * EliminarTodo(struct nodo* Pila){
    struct nodo* aux;
    while(Pila != NULL){
        aux=Pila;
        Pila=Pila->ptr;
        free(aux);
    }
    Pila=NULL;
    return Pila;
};

struct nodo* AgregarInicio(struct nodo* Pila){
    struct nodo* aux;
    int n;
    printf("Ingresar valor nuevo: ");
    scanf("%d", &n);
    aux= (struct nodo*)malloc(sizeof(struct nodo));
    aux->dato=n;
    (*aux).ptr=Pila;
    Pila=aux;
    return Pila;
};

struct nodo* AgregarFinal(struct nodo* Pila){
    struct nodo* aux;
    struct nodo* act=Pila;
    struct nodo* ant=Pila;
    aux= (struct nodo*) malloc(sizeof(struct nodo));
    printf("Ingrese valor para agregar al final: ");
    int n;
    scanf("%d", &n);
    aux->dato=n;
    while(act != NULL){
        ant=act;
        act=act->ptr;

    }
    if(Pila == NULL){
        (*aux).ptr=NULL;
        Pila=aux;
    }else{
    (*aux).ptr=act;
    (*ant).ptr=aux;
}
return Pila;
}

int CalcularNodos(struct nodo* Pila){
    int cant=0;
    struct nodo* aux= Pila;
    while(aux != NULL){
        cant++;
        aux=(*aux).ptr;
    }
    return cant;
}
