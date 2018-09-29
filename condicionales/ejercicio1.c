#include <stdio.h>

int main(){

    float x;

    printf("Valor cualquiera N \n");
    scanf("%f",&x);

    if (x < 0){
        printf("Es negativo");
    }
    else{
        if(x == 0){
            printf("Es cero");
        }
        else{
            printf("Es positivo");
        }
    }

    getchar();
    return (0);

}

