#include <stdio.h>

int main(){

    printf("Escriba un numero entero");
    scanf("%d",&n);

    print("Escriba a que base quiere convertirlo");
    scanf("%d",&base);

    cociente= n;

    while(n>base){
        n = (n/base);
        printf("%d",n);



    }

}
