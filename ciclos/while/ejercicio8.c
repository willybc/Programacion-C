#include <stdio.h>

int main(){

    int n;

    printf("Escriba un valor entero positivo\n");
    scanf("%d",&n);

    if(n==1){
        printf("El numero uno no se considera ni primo ni compuesto\n");
    }
    else{

        if( (n%2==0) && (n%(n/2))==0){
        printf("NO ES PRIMO\n");
        }
            else{
                printf("ES PRIMO\n");
            }
        }

        getchar();

    return 0;
    }
