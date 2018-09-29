#include <stdio.h>

int main(){

    int n ;
    int contador = 1;
    int total= 1;
    printf("Escribir algun numero para saber su factorial\n");
    scanf("%d",&n);

    while(contador<=n){
        total = total * contador;
        contador++;
    }




    printf("El factorial del numero %d es %d\n",n,total);

    return 0;

    getchar();
}
