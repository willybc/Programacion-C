#include <stdio.h>

int main(){

    float a,b;

    printf("Numero 1\n");
    scanf("%f",&a);

    printf("Numero 2\n");
    scanf("%f",&b);

    if(a<0 || b<0){
        printf("Signos opuestos\n");
    }

    return(0);
    getchar();

}
