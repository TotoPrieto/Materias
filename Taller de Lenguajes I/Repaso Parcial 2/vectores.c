#include <stdio.h>
#include "vectores.h"

float sumaa(float vec[], int cant){
    float sum=0;
    int i;
    for (i=1; i<cant; i++){
        sum+= vec[i];
    }
    return sum;
}

float promedioo(float vec[], int cant){
    float x= sumaa(vec, cant);
    return x/((float)(cant-1));
}
