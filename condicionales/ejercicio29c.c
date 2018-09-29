#include <stdio.h>

int main(){

    int valor,resultado;
    printf("Introduce un numero entero:");
    scanf("%d",&valor);

    resultado = (valor%2==0 && valor>10);
    //cualquier valor que sea distinto a cero va a ser verdadero
    //esta sera cierta siempre q "x" sea distinto a cero
    // resultado == 0 entonces sera falso
    if(resultado){
        printf("el numero es par y es mayor a 10");
    }
    else{
        printf("no ha cumplido");
    }


}

