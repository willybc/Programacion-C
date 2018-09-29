#include <stdio.h>

int main(){

    int valor,resultado;
    printf("Introduce un numero entero:");
    scanf("%d",&valor);

    resultado = valor%7;
    //cualquier valor que sea distinto a cero va a ser verdadero
    //esta sera cierta siempre q "x" sea distinto a cero
    if(resultado){
        printf("El numero introducido no es multiplo de 7");
    }
    else{
        printf("El numero introducido es multiplo de 7");
    }


}
