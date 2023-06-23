#include <stdio.h>
#include <stdlib.h>
#include "vectores.h"

#define MACRO(x , y)  x ## y

int main(int argc, char* argv[]){
    int i;
    float x;
/*
    float vec[argc-1];
    for(i=1;i<argc;i++){
        x=atof(argv[i]);
        vec[i]=x;
        printf("argv[%d]--> %f \n",i,x);
    }

    printf("La suma es: %f", sumaa(vec, argc));
    printf("El promedio es: %f", (promedioo(vec, argc)));
  */
    printf("%s", MACRO( l , o ));
    return 0;
}
