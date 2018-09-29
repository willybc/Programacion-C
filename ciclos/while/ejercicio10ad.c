#include <stdio.h>

int main(){

    int contador;
    int fahr;
    float celsius;

    printf("Escriba en grados Fahrenheit para convertir a grados Celsius\n");
    scanf("%d", &fahr);

    printf("------------------------\n");

    while(fahr!=101){
        celsius = ((float) (fahr - 32) * 5/9);
        printf("%d equivale a %.1f\n", fahr , celsius);

        fahr = fahr +1;
    }

}
