/*
a. Stack* s_create () – Retorna una nueva pila. Se debe invocar antes de
manipular cualquiera de ellas.
b. int s_push(stack* s, int n) – Apila n en s. Retorna el elemento apilado.
c. int s_pop (stack* s) – Desapila un elemento de s.
d. int s_top (stack s) – Retorna el próximo elemento que será desapilado.
e. int s_empty(stack s) – Retorna 1 si s está vacía, 0 en caso contrario.
f. int s_length(stack s) – Retorna la cantidad de elementos apilados en s.

*/
#include <stdlib.h>
#include <stdio.h>
#include "istack.h"

Stack* s_create(){
    Stack* nueva;
    nueva=(Stack*) malloc (sizeof(Stack));
    nueva->pila=NULL;
    nueva->tamanio=0;
    return nueva;
}

int s_push(Stack* s, int n){
    nodo* aux=(nodo*) malloc (sizeof(nodo));
    aux->dato=n;
    aux->ptr=s->pila;
    s->pila=aux;
    s->tamanio++;
    return (s->pila->dato);
}

int s_pop (Stack* s){
    int i=s->pila->dato;
    nodo* aux=s->pila;
    s->pila=s->pila->ptr;
    free(aux);
    return (i);

}
int s_top (Stack s){
    return s.pila->ptr->dato;
}

int s_empty(Stack s){
    if(s.pila==NULL)
        return 1;
    else
        return 0;
}

int s_length(Stack s){
    return s.tamanio;
}


