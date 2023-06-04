/*
a) ¿El código compila? ¿Por qué?
b) ¿Qué sucedería al cambiar la constante simbólica DEBUG al valor 1? Evalúe el comportamiento del
código. ¿Qué beneficios trae en este caso la compilación condicional?
c) ¿Es posible cambiar el valor de la constante simbólica DEBUG en tiempo de ejecución?
d) ¿Qué sucede si en lugar de utilizar la directiva #if se emplea #ifdef? ¿Incide el valor de la
constante simbólica DEBUG en el resultado de la compilación?
*/
#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0
int main(){
    int x= 15,y=0;
    while (x<50){
        #ifdef DEBUG
        printf("x= %d    ", x);
        y= y+1;
        #endif
        x++;

    }

    return 0;
}


//El preprocesado se realiza antes de correr el programa, por lo que no se puede cambiar en tiempo de ejecicion
//el ifdef realiza la condicion de si esta declarada esa constante, sin importar el valor que esta tenga
