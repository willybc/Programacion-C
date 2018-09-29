#include <stdio.h>

int main(){

    int valor,resultado;
    printf("Introduce un numero entero:\n");
    printf("si es impar y menor o igual a 10 sera falso\n");
        printf("si alguno de los valores de adentro es falso , sera verdadero\n");
    scanf("%d",&valor);

    resultado = !(valor%2!=0 && valor<=10);
    //cualquier valor que sea distinto a cero va a ser verdadero
    //esta sera cierta siempre q "x" sea distinto a cero
    // resultado == 0 entonces sera falso
    if(resultado){

        printf("Es VERDADERO");
    }
    else{
        printf("Es FALSO");
    }


}

