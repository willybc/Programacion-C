#include <stdio.h>

int main(){

    int n,z,w;

    printf("N?\n");
    scanf("%d",&n);

    printf("w?\n");
    scanf("%d",&w);

    printf("z?\n");
    scanf("%d",&z);

    if ( (n%w==0) && (n%z==0) ){
        printf("Es comun divisor de los dos");
    }
    else{
        printf("No es comun divisor de los dos");
    }
    getchar();
}

