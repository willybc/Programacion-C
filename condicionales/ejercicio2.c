#include <stdio.h>

int main(){

    float a,b;

    printf("Valor a \n");
    scanf("%f",&a);

    printf("Valor b \n");
    scanf("%f",&b);

    if (a > b){
        printf("%.1f es el mayor", a);
    }
    else{
            printf("%.1f es el mayor", b);
    }

    getchar();
    return (0);

}

