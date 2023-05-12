#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

typedef struct cuadrado{
    float lado1;
    float lado2;
}cua;

typedef struct triangulo{
    float lado1;
    float lado2;
    float lado3;
}tri;

typedef struct elipse{
    float radio1;
    float radio2;
}el;

typedef struct circulo{
    float radio;
}cir;

typedef struct rectangulo{
    float base;
    float altura;
}rec;
union formas{;
    cua Cu;
    tri T;
    el E;
    cir Ci;
    rec R;
};

typedef enum{CUADRADO=1,TRIANGULO,ELIPSE,CIRCULO,RECTANGULO}fofofo;

typedef struct fo{
    union formas F;
    fofofo tipo;
    float sup;
}coso;


void CalcularF(coso*);
int main(){
    coso X;
    X.tipo=CIRCULO;
    X.F.Ci.radio=4.6;
    CalcularF(&X);
    printf("Su superficie es %f",X.sup);
    return 0;
}

void CalcularF(coso* x){
    switch (x->tipo){
        case 1: x->sup=(x->F.Cu.lado1 * x->F.Cu.lado2);
        break;
        case 2: x->sup=(x->F.T.lado1 * x->F.T.lado2 * x->F.T.lado3);
        break;
        case 3: x->sup=(x->F.E.radio1 * x->F.E.radio2 * PI);
        break;
        case 4: x->sup=(x->F.Ci.radio * x->F.Ci.radio * PI);
        break;
        case 5: x->sup=(x->F.R.base * x->F.R.altura);
        break;
    }

}
