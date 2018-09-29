#include <stdio.h>

int main(){

    float num , contador;

    contador = 0;

    printf("Escriba un numero para contar los digitos\n");
    scanf("%f",&num);

    while(num>=1){
            num= (0.1 * num);
            contador = (contador +1);
    }

    printf("Tiene en total %.0f\n", contador);

}
