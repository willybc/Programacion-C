#include <stdio.h>

int main(){

    int a,b,c;

    printf("A\n");
    scanf("%d",&a);

    printf("B\n");
    scanf("%d",&b);

    printf("C\n");
    scanf("%d",&c);

    if ( (a+b)==c ) {
        printf("La suma de los dos numeros es igual a C");
    }
    else{
        printf("La suma de los dos numeros no es igual a C");
    }
    getchar();
}



