#include "vec.h"
#include <stdio.h>
#include <string.h>

#define N 10

void menu(){
    printf("Menu de funciones\n");
    printf("1: Leer\n");
    printf("2: Leer elemento leidos con valor a\n");
    printf("3: Veces \n");
    printf("4: Invertir Orden \n");
}

void carga ( int v[], int n){
    int i;
    for ( i=0; i <n ; i++){
        v[i] = i+1;
    }
}

void emitir ( int v[], int n) {
    int i;
    printf("Registros \n");
    for ( i=0;i<n;i++){
        printf("%d \n",v[i]);
    }
}

void leer ( int v[] ){
    int i,m;
    printf("Valor de elementos ? \n");
    scanf("%d",&m);
    for ( i=0; i<m; i++){
        v[i] = i+1;
    }
}

int leerMarca( int v[]){
    int i, a , contador=0;
    printf("Valor a ?\n");
    scanf("%d",&a);

    for( i=0 ; i<a; i++){
        v[i] = contador + i;
        if(i==a-1){
            printf("Numero de elementos leidos : %d \n",v[i]);
        }
    }
    return contador;
}

int veces ( int valor , int v[], int contador){
    int i;

    for ( i=0 ; i<N ; i++){
        printf("escriba valores\n");
        scanf("%d",&v[i]);

        if(v[i] == valor){
            contador++;
        }
    }
    printf("Numero de apariciones del elemento %d en el vector es de: %d",valor,contador);
}


void invertirOrden(int v[]){
    int i;
    for ( i=9 ; i>=0 ; i--){
        printf("El valor de la posicion %d es :% d \n",i+1,v[i]);
        //Error funcion , valores incorrectos
    }

}


