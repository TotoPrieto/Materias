#include <stdio.h>
#include <stdlib.h>

typedef enum {
    BLUETOOTH = 1,
    WIFI=2,
    GPS=4,
    DATOS=8,
    CAMARA_F=16,
    CAMARA_T=32,
    LINTERNA=64,
    VIBRAR=128
} modulo;

struct todos{
    unsigned char vib:1;
    unsigned char lin:1;
    unsigned char ct:1;
    unsigned char cf:1;
    unsigned char dat:1;
    unsigned char gp:1;
    unsigned char wif:1;
    unsigned char blu:1;
};
void Llamar(char*);
void verBits(struct todos);
int EsActivo(struct todos,modulo);
void Invertir(struct todos*);
void Desactivar(struct todos*,modulo);
void Activar(struct todos*, modulo);
int main(){
    char texto[]="Hola";
    Llamar(texto);
    Llamar("Desde");
    Llamar("Casa");
    char *p; char c; char s[10];
    p = s+5;
    struct todos x;
        x.blu=1;
        x.wif=0;
        x.gp=0;
        x.dat=0;
        x.cf=0;
        x.ct=0;
        x.lin=0;
        x.vib=1;
    printf("%d\n",&x+1);
    modulo A=WIFI;
    verBits(x);
    Activar(&x,A);
    verBits(x);
    A=VIBRAR;
    Desactivar(&x,A);
    verBits(x);
    Invertir(&x);
    verBits(x);
    A=DATOS;
    if (EsActivo(x,A)==1){
        printf("Ese bit es activo");
    }else{
    printf("No es activo");
    }
    return 0;
}

void Activar(struct todos* num,modulo A){
    switch(A){
        case 1: num->blu=1;
        break;
        case 2: num->wif=1;
        break;
        case 4: num->gp=1;
        break;
        case 8: num->dat=0;
        break;
        case 16: num->cf=1;
        break;
        case 32: num->ct=1;
        break;
        case 64: num->lin=1;
        break;
        case 128: num->vib=1;
        break;
    }
}
void Llamar(char * s) {
 static char * p1 = NULL;
 if (p1==NULL){
 p1 = s;
 printf("Nada\n");
 }
 else
 printf("%s\n", p1);
}

void Desactivar(struct todos* num, modulo A){
    switch(A){
        case 1: num->blu=0;
        break;
        case 2: num->wif=0;
        break;
        case 4: num->gp=0;
        break;
        case 8: num->dat=0;
        break;
        case 16: num->cf=0;
        break;
        case 32: num->ct=0;
        break;
        case 64: num->lin=0;
        break;
        case 128: num->vib=0;
        break;
    }
}
void Invertir(struct todos* num){
    num->blu=~num->blu;
    num->wif=~num->wif;
    num->gp=~num->gp;
    num->dat=~num->dat;
    num->cf=~num->cf;
    num->ct=~num->ct;
    num->lin=~num->lin;
    num->vib=~num->vib;
}
int EsActivo(struct todos num,modulo A){
        switch(A){
        case 1: return num.blu;
        break;
        case 2: return num.wif;
        break;
        case 4: return num.gp;
        break;
        case 8: return num.dat;
        break;
        case 16: return num.cf;
        break;
        case 32: return num.cf;
        break;
        case 64: return num.lin;
        break;
        case 128: return num.vib;
        break;
    }
}

void verBits(struct todos x){
    printf("%d%d%d%d.%d%d%d%d\n",x.vib,x.lin,x.ct,x.cf,x.dat,x.gp,x.wif,x.blu);
}




