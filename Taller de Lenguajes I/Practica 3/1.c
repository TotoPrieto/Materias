#include <stdio.h>
#include <stdlib.h>


struct Rectangulo{
    float base;
    float altura;
}R[3];

float calcularArea(struct Rectangulo);
int Ejercicio1()
{
    float min=999,act;
    int num;
    int i;
    for (i=0;i<3;i++){
        printf("Ingresar altura de rectangulo ");
        scanf("%f", &R[i].altura);
        printf("Ingresar base de rectangulo ");
        scanf("%f", &R[i].base);
        act=calcularArea(R[i]);
        if(min>act){
            min=act;
            num=i;
        }
    }
    printf("El min es el indice %d, con %f.",num,min);
    return 0;
}

float calcularArea(struct Rectangulo R){
    return(R.altura*R.base);
}
