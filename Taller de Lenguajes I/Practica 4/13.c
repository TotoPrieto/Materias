/* Escriba un programa que trabaje con una matriz de enteros utilizando las declaraciones
anteriores sin importar el orden de acceso a cada dimensión (fila y columna o columna y fila).
Cargue a m con valores leídos desde teclado y luego imprima sus valores en pantalla para
verificar que se cargó correctamente. Por último, libere la memoria reservada
*/
void Imprimir(int *, int, int);
void Asignar(int *,int , int );
int main(){
    int x=2, y=3;
    int * m= (int*) malloc(x*y*sizeof(int));
    Asignar(m, x, y);
    Imprimir(m,x,y);
    free(m);
    Imprimir(m,x,y);
    return 0;
}


void Asignar(int *m,int x, int y){
int i;
for (i=0; i<(x*y); i++){
    printf("Valor a asignar a %d: ",i);
    scanf("%d",&m[i]);
}
}

void Imprimir(int *m, int x, int y){
    int i;
    for(i=0; i<(x*y); i++){
        printf("VALOR %d: %d\n",i, m[i]);
    }

}