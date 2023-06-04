/*
a. Investigue las funciones de conversión de texto a número y escriba un programa “calculadora.c” que
reciba dos números enteros y un operador como argumentos a la función main e imprima en pantalla el
resultado de la operación. El operador debe ser: “+”, “-”, “/”, “.”. Si el operador recibido no es uno de los
mencionados anteriormente, entonces el programa debe imprimir un mensaje de error.
b. Utilice una terminal para compilar el programa a través de la línea de comandos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

//Primero los dos nuemeros y despues la operacion
int main (int argc, char * argv[]) {
    int i;
    float resultado=0;
    float a, b;
    char* operador;
    a=atof(argv[1]);
    b=atof(argv[2]);
    operador=argv[3];

    printf("%f %s% f == ",a,operador,b);
    switch(*operador){
        case '+': resultado= a+b;
        break;
        case '-': resultado= a-b;
        break;
        case '*': resultado= a*b;
        break;
        case '/': resultado= a/b;
        break;
        default: printf("La pifiaste wachin");
        break;
    }
    printf("%f", resultado);
return 0;
}