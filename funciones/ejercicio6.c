#include <stdio.h>

void tabla_multiplicar ( int x);

int main () {
    int i;

    for ( i =1 ; i<= 10 ; i++){
        printf("Tabla de multiplicar del %d \n\n", i);
        tabla_multiplicar (i);
    }
}

void tabla_multiplicar ( int x){
    int j , mult;

    for ( j =1 ; j<= 10 ; j++){
        mult = x * j ;
        printf("%d * %d = %d \n", x , j , mult);
    }
}
