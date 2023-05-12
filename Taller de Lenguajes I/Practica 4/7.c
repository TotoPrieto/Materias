/* Utilizando la estructura y funciones del ejercicio anterior escriba un programa que lea números
enteros positivos desde teclado hasta ingresar el número 0. Los números leídos deben ser almacenados
en orden ingresado por teclado. Generar una nueva lista con el orden invertido. Imprimir los
elementos de cada lista junto con la cantidad de elementos de cada una. Por último, libere la memoria
reservada dinámicamente.
 */
#include <stdio.h>
#include <stdlib.h>


struct nodo{
        int dato;
        struct nodo * ptr;
    };

struct nodo* CrearNuevaLista(struct nodo*,struct nodo*);

int CalcularNodos(struct nodo*);

struct nodo*  AgregarFinal(struct nodo*);

struct nodo* AgregarInicio(struct nodo*,int);

struct nodo * EliminarTodo(struct nodo*);

void Leer(struct nodo *);

struct nodo* Inicializar(struct nodo *);

int main(){
    struct nodo *Pila=NULL, *Pila2=NULL;

    Pila=Inicializar(Pila);
    Leer(Pila);
    printf("\n");
    Pila2=CrearNuevaLista(Pila, Pila2);
    Leer(Pila2);
    printf("\nLa cantidad de nodos de las listas es: %d",CalcularNodos(Pila));
    Pila=EliminarTodo(Pila);
    Pila2=EliminarTodo(Pila2);
    return 0;
}

struct nodo* Inicializar(struct nodo *Pila){
    int n;
    struct nodo * aux;

    printf("Ingrese un valor para la lista: ");
    scanf("%d", &n);
    while(n!=0){
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

struct nodo* AgregarInicio(struct nodo* Pila2, int n){
    struct nodo* aux;
    aux= (struct nodo*)malloc(sizeof(struct nodo));
    aux->dato=n;
    (*aux).ptr=Pila2;
    Pila2=aux;
    return Pila2;
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

struct nodo* CrearNuevaLista(struct nodo* Pila, struct nodo* Pila2){
    struct nodo* aux=Pila;
    while(aux !=NULL){
        Pila2=AgregarInicio(Pila2, aux->dato);
        aux=(*aux).ptr;
    }
    return(Pila2);
};
