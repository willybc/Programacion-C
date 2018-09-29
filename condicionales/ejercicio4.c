#include <stdio.h>

int main(){

    int a,b;

    printf("Valor a \n");
    scanf("%d",&a);

    printf("Valor b \n");
    scanf("%d",&b);


    if (b % a == 0){
        printf("divide exactamente a A");
    }
    else{
        if (b % a == 0){
        printf("A divide exactamente a B");
        }
        else{
            printf("Ninguno de los dos divide exactamente al otro");
        }
    }



    getchar();
    return (0);

}
