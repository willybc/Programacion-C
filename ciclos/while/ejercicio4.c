#include <stdio.h>

int main(){

    int n , cuenta,valor,valor2,suma;

    cuenta = 0;

    printf("Cuantas veces?\n");
    scanf("%d",&n);

    valor = 1;
    valor2 = -1;

    printf("%d\n",valor);

    while(cuenta!=n){
        valor = (valor + 2);
        printf("%d+",valor);

        valor2 = (valor2 + 2);
        printf("%d=\n", valor2);

        suma = (valor + valor2);
        printf("%d\n\n", suma);

        cuenta = (cuenta +1);
    }
}
