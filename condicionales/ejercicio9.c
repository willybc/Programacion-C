#include <stdio.h>

int main(){

    int a,b,c;
    int med;

    printf("Valor a \n");
    scanf("%d",&a);

    printf("Valor b \n");
    scanf("%d",&b);

    printf("Valor c \n");
    scanf("%d",&c);

    if(a>b && c>a || a>c && b>a){
        (med=a);
    }
    else{
        if (b>a && c>b || b>c && a>b){
            (med=b);
        }
        else {
            if( (c>a && b>c) || (c>b && a>c) ){
                (med=c);
                }
        }
    }



    printf("El valor del centro es %d", med);

    getchar();
    return (0);

}



