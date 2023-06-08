
/*
a. Stack* s_create () – Retorna una nueva pila. Se debe invocar antes de
manipular cualquiera de ellas.
b. int s_push(stack* s, int n) – Apila n en s. Retorna el elemento apilado.
c. int s_pop (stack* s) – Desapila un elemento de s.
d. int s_top (stack s) – Retorna el próximo elemento que será desapilado.
e. int s_empty(stack s) – Retorna 1 si s está vacía, 0 en caso contrario.
f. int s_length(stack s) – Retorna la cantidad de elementos apilados en s.
*/
#ifndef ISTACK_H_INCLUDED
#define ISTACK_H_INCLUDED

struct NODO{
    int dato;
    struct NODO *ptr;
};
typedef struct NODO nodo;

typedef struct{
    nodo *pila;
    int tamanio;
} Stack;


Stack* s_create();
int s_push(Stack* s, int n);
int s_pop (Stack* s);
int s_top (Stack s);
int s_empty(Stack s);
int s_length(Stack s);

#endif // ISTACK_H_INCLUDED

