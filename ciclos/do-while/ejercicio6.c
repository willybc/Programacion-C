#include <stdio.h>

int main(){

    float reciproco,n;

    printf("Para terminar el programa escriba (0)\n");

    do{
        printf("Escriba un numero\n");
        scanf("%f",&n);

        reciproco = (1/n);

        if(n!=0){
            printf("El reciproco es %.2f\n", reciproco);
        }
        else{
            printf("Se finalizo el programa correctamente\n");
        }

    }while(n!=0);

    return 0;



}
