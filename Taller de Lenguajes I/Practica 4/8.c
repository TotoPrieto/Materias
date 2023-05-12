/* Utilizando la estructura y funciones de los ejercicios anteriores escriba un programa que lea números
enteros desde teclado hasta ingresar el número 0. Luego, vuelva a leer otro número entero desde
teclado y elimine de la lista a todos aquellos que sean múltiplos del mismo
 */
#include <stdio.h>
#include <stdlib.h>


struct nodo{
        int dato;
        struct nodo * ptr;
    };

struct nodo * EliminarMultiplos(struct nodo*, int);

void Leer(struct nodo *);

struct nodo* Inicializar(struct nodo *);

int main(){
    struct nodo *Pila=NULL, *Pila2=NULL;
    int n=0;
    Pila=Inicializar(Pila);
    Leer(Pila);
    printf("\nIngrese un valor a eliminar, y sus multiplos: ");
    scanf("%d",&n);
    Pila=EliminarMultiplos(Pila,n);
    Leer(Pila);

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

struct nodo * EliminarMultiplos(struct nodo* Pila, int n){
    struct nodo* aux=Pila, *ant=Pila;
    struct nodo* act=Pila;
    while(act != NULL){
        if(((*act).dato)%n==0){
            aux=act;
            if(act==ant){
                    Pila = act->ptr;
                    free(act);
                    act = Pila;
                    ant = Pila;
            }else{
            ant->ptr=act->ptr;
            free(act);
            act = ant->ptr;
            }
        }else{
            ant = act;
            act=act->ptr;
        }
    }
    return Pila;
}
