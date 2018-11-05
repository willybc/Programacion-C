#include "vec.h"
#include <stdio.h>
#include <string.h>

#define N 10
void carga ( int v[], int n){
    int i;
    for ( i=0; i <n ; i++){
        v[i] = i+1;
        printf("%d \n",v[i]);
    }
}
