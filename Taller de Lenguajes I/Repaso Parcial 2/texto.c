#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct resultado{
    int posL;
    int posA;
};
typedef struct resultado res;

int main(){
    FILE* t, * b;
    t= fopen("t.txt","r");
    if (t!=NULL){
        b=fopen("b.dat","wb+");
        if(b!=NULL){
            int act=0, tot=0;
            res resultado;
            char* basura;
            do{
                act=fscanf(t,"%s",&basura);
                tot=ftell(t);
                resultado.posA=tot;
                //act= strlen(&basura);
                resultado.posL=act;
                fwrite(&resultado,sizeof(res),1,b);

            }while(!feof(t));

            fseek(b,0, SEEK_SET);
            fread(&resultado, sizeof(res),1,b);
            while(!feof(b)){

                printf("%d - %d\n", resultado.posL, resultado.posA);
                fread(&resultado, sizeof(res),1,b);
                }
        }
        fclose(b);
    }
    fclose(t);


    return 0;
}
