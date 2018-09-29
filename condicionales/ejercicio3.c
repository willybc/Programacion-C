#include <stdio.h>

int main(){

    int a,b,contrario,mayor;

    printf("Valor a \n");
    scanf("%d",&a);

    printf("Valor b \n");
    scanf("%d",&b);

    if (a > b){
        mayor = a;
        contrario = b;
    }
    else{
        mayor = b;
        contrario = a;
    }

    if (mayor % contrario == 0){
        printf("El mayor es divisible al menor que es %d",contrario);
    }
    else{
        printf("No es divisible al menor");
    }


    getchar();
    return (0);

}

