#include <stdio.h>

int main(){

    int n , cuadrado;

    printf("Escribir numero para saber el cuadrado\n");

    while(n!=0){
        scanf("%d",&n);

        cuadrado = (n*n);

        if(n!=0){
            printf("El cuadrado del numero %d es %d\n", n,cuadrado);
        }
        else{
            printf("El programa se esta cerrando...");
        }


    }

    return 0;

        getchar();
}
