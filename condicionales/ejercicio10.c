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

    if(a%b==0 && a%c==0 ){
        printf("a se divide exactamente con los otros 2\n");
    }

    if(b%a==0 && b%c==0 ){
        printf("b se divide exactamente con los otros 2\n");
    }

    if(c%a==0 && c%b==0 ){
        printf("c se divide exactamente con los otros 2\n");
    }

    getchar();
    return (0);
}
