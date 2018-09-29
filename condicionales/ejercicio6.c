#include <stdio.h>

int main(){

    int a,b,suma;

    printf("Valor a \n");
    scanf("%d",&a);

    printf("Valor b \n");
    scanf("%d",&b);

    suma = a+b;

    if (suma % 2 == 0){
        printf("La suma de los 2 numeros es par");
    }
    else{
        printf("La suma de los 2 numeros es impar");
    }



    getchar();
    return (0);

}
