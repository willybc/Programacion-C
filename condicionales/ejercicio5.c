#include <stdio.h>

int main(){

    int a;

    printf("Valor a \n");
    scanf("%d",&a);

    if (a % 2 == 0){
        printf("Es par");
    }
    else{
        printf("Es impar");
    }

    getchar();
    return (0);

}
