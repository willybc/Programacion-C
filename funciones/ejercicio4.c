#include <stdio.h>

void factorial ( float x);

int main() {

float num ;

printf("Escriba numero \n");
scanf ("%f", &num);

factorial (num);
}

void factorial ( float x){
    float i , fact = 1;

    for ( i = x ; i > 1 ; i--){
        fact = fact * i;
    }
    printf("El factorial es %.2f",fact);
}
