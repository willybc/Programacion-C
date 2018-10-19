#include <stdio.h>

int main(){

    char nombre[31];
    int nota;

    FILE * archa ;
    archa = fopen("alum.dat","rt");

    while(nota!=0){
        fscanf(archa,"%s",nombre);
        fscanf(archa,"%d",&nota);
        if(nota >= 9){
            printf(" %s \n", nombre);
        }
    }
}
