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
}x;

void verBits(unsigned);
int EsActivo(unsigned,modulo);
unsigned Invertir(unsigned);
unsigned Desactivar(unsigned,modulo);
unsigned Activar(unsigned, modulo);
int main(){
        /*x.blu=1;
        x.wif=0;
        x.gp=0;
        x.dat=0;
        x.cf=0;
        x.ct=0;
        x.lin=0;
        x.vib=1;*/
    unsigned num=8;
    modulo A=WIFI;
    num=Activar(num,A);
    printf("%u\n",num);
    A=DATOS;
    num=Desactivar(num,A);
    printf("%u\n",num);
    //num=Invertir(num);
    //printf("%u\n",num);
    verBits(num);
    A=WIFI;
    if (EsActivo(num,A)==1){
        printf("Ese bit es activo");
    }else{
    printf("No es activo");
    }
    return 0;
}

unsigned Activar(unsigned num,modulo A){
    return num|A;
    }
unsigned Desactivar(unsigned num, modulo A){
    return num&(~A);
}
//unsigned Invertir(unsigned num){
    //return ~num;
//}
int EsActivo(unsigned num,modulo A){
    if(num&(~A)!=num){
        return 0;
    }else{
    return 1;
    }
}

void verBits(unsigned valor){
  unsigned int mascara = 1<<7;
  int i;

  printf("%u = ", valor);
/*
  for (i=1; i<=32; i++){
    putchar(valor & mascara ? '1' : '0');
    valor = valor <<1;
    if (i % 8 == 0)
        printf(" ");
  }

*/
  i=1;
  while (mascara > 0){
    printf("%c",valor & mascara ? '1' : '0');
    mascara = mascara >> 1;

    if (i++ % 4 == 0)
        printf(" ");
  }
   printf("\n");
}






