#include <stdio.h>

void calculador_potencia ( int z , int x);

int main(){
    int exponente;
    double base;

    printf("Introduzca la base y el exponente : \n");
    scanf("%lf %d", &base , &exponente);

    calculador_potencia ( base , exponente);
}

void calculador_potencia ( int z , int x) {

    double potencia;
    int i ;
    potencia = 1;

    for(i=0 ; i<x ; i++){
        potencia = potencia * z;
        printf("La potencia es %lf \n", potencia);
    }

}
