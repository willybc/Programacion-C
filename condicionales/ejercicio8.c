#include <stdio.h>

int main(){

    int a,b,c;
    int max;

    printf("Valor a \n");
    scanf("%d",&a);

    printf("Valor b \n");
    scanf("%d",&b);

    printf("Valor c \n");
    scanf("%d",&c);

    if(a>b && a>c){
        (max=a);
    }
    else{
        if (b>a && b>c){
            (max=b);
        }
        else {
            (max=c);
        }
    }

    printf("El mayor es %d", max);

    getchar();
    return (0);

}


