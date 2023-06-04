#include <stdio.h>
#include <stdlib.h>
int main (int argc, char * argv[]) {
    int i;
    float resultado=0;
    for(i=0;i<argc;i++){
        printf("\nargv[%d]-->%s",i,argv[i]);
        resultado+= atof(argv[i]);
    }
    resultado= resultado/(argc-1);
    printf("\nEl promedio de los valores ingresados fue: %f", resultado);
return 0;
}
