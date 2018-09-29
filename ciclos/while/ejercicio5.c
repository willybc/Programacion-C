#include <stdio.h>

int main(){

    int n,contador;
    int a,min,max;
    int b;
    float promedio,suma;

    contador =0;

    max=-9999;
    min=9999;

    suma=0;


    printf("cuantos numeros naturales?\n");
    scanf("%d",&n);

    printf("Ingresa los numeros naturales \n");

    while(contador!=n){
        contador = contador +1;

        scanf("%d",&a);

        /*SUMA */
        suma = suma + a;

        /*VALOR MAXIMO Y VALOR MINIMO*/
        if(a>max){
                max = a;
        }
        if(a<min){
                min = a;
        }
        /*VALOR MAXIMO Y VALOR MINIMO*/
    }

    /*PROMEDIO */
        promedio = suma/n;
    /* PROMEDIO */

    printf("El maximo es %d\n",max);
    printf("El minimo es %d\n",min);
    printf("La suma es de %.0f\n",suma);
    printf("El promedio es de %.2f\n",promedio);

}
