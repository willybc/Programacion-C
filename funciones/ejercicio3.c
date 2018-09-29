#include <stdio.h>

void numero_mayor ( int x , int y);

int main(){

int num1, num2;

printf("Numero 1 \n");
scanf("%d" , &num1);

printf("Numero 2 \n");
scanf("%d" , &num2);

numero_mayor(num1 , num2);

}

void numero_mayor ( int x , int y) {

if( x > y){
    printf("El numero %d es mayor \n " , x);
}
else{
    if( x == y) {
        printf("Son numeros iguales \n ");
    }
    else{
        printf("El numero %d es mayor \n", y);
    }
}

}
