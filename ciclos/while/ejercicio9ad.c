#include <stdio.h>

int main(){

    printf("Escriba un valor positivo para convertirlo a base binaria");
    scanf("%d", &num);

    if(num == 1){
        printf("El valor es 0001");
    }
    else{
        while(num!=1){
            num = num/2;
            resto = num%2;

            }
        }
    }
