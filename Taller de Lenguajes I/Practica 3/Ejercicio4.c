#include <stdio.h>
#include <stdlib.h>
/*#define Espada "Espada";
#define Oro 2 "Oro";
#define Basto 3 "Basto";
#define Copa 4 "Copa";
*/
struct mazo{
    int num;
    int palo;
    };

typedef  struct mazo m;

void Barajar(m *);
char* Sacar(int);
int main(){
    m carta[48];
    Barajar(&carta);
    printf("Barajeaste el mazo. \n");
    int i=rand()%48;
    printf("La carta que sacaste fue el %d de %s \n",carta[i],Sacar(carta[i].palo));
    return 0;
}

void Barajar(m *ca){
    int i,j,n=0,palo;
    for(i=1;i<=12;i++){
        palo=1;
        for(j=0;j<4;j++){
            ca[n].palo=palo++;
            ca[n].num=i;
            n++;
        }
    }
    }
char* Sacar(int palo){
    switch(palo){
    case 1: return("Espada");
    break;
    case 2: return("Oro");
    break;
    case 3: return ("Basto");
    break;
    case 4: return ("Copa");
    break;
    }
}
