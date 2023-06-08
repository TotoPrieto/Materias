#include <stdio.h>
#include "istack.h"

int main(){
    Stack * cola =s_create();
    s_push(cola, 5);
    printf("Valor almacenado %d\n", s_pop(cola));
    s_push(cola, 8);
    printf("Valor almacenado %d\n", s_pop(cola));

    printf("Cantidad de elementos en la pila: %d\n", s_length(*cola));
    printf("Pop de pila %d\n", s_pop(cola));
return 0;
}
