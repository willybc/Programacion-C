#include <stdio.h>

int main(){

    float a,b , cociente;

    printf("Valor a \n");
    scanf("%f",&a);

    printf("Valor b \n");
    scanf("%f",&b);

    cociente = a/b;

    if (b != 0){
        printf("El cociente de a/b es %.1f",cociente);
    }
    else{
        printf("No se puede dividir por cero");
    }

    getchar();
    return (0);

}

