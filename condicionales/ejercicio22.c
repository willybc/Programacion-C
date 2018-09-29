#include <stdio.h>

int main(){

    int ano, cuenta;

    printf("Ano?\n");
    scanf("%d",&ano);

    if( (ano%4==0) && !(ano%100==0) ){
        printf("Es bisiesto\n");
    }
    else{
            if (ano%400==0){
                printf("Es bisiesto\n");
            }
            else{
            printf("No es bisiesto\n");
            }
    }
}
