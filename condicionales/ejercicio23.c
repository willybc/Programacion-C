#include <stdio.h>

//Ejercicio hecho segun la teoria "DESIGUALDAD TRIANGULAR"

int main(){

    int lado1, lado2, lado3;

    printf("lado1?\n");
    scanf("%d",&lado1);

    printf("lado2?\n");
    scanf("%d",&lado2);

    printf("lado3?\n");
    scanf("%d",&lado3);

    if( (lado1<(lado2+lado3) ) && (lado2<(lado1+lado3) ) && (lado3<(lado1+lado2) ) ){
        printf("Se puede formar un triangulo : ");

        if( (lado1 == lado2) && (lado3 == lado1) ){
        printf("Equilatero");
        }
        else{
            if( (lado1 == lado2) || (lado1== lado3) || (lado2 == lado3) ){
                printf("Isosceles");
            }
            else{
                printf("Escaleno");
            }
        }
    }
    else{
        printf("No se puede formar ningun triangulo ");
    }

    getchar();



}

