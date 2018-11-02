#include "vec.h"
#include <stdio.h>
#include <string.h>

void carga ( int v[], int n){
    int i;
    for ( i=0; i <n ; i++){
        printf("edad\n");
        scanf("%d",&v[i]);
    }
}

void emitir ( int v[], int n) {
    int i;
    printf("Registros \n");
    for ( i=0;i<n;i++){
        printf("%d \n",v[i]);
    }
}
