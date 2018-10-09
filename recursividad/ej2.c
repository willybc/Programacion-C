#include <stdio.h>

int suma (int a, int b);

int main(){

    int a,b , result;

    printf("valor a? \n");
    scanf("%d",&a);

    printf("valor b? \n");
    scanf("%d",&b);

    result = suma ( a , b);
    printf("%d + %d = %d", a , b , result);

    return 0;
}

int suma (int a, int b){
    if (b==0){
        return a;
    }
    else{
        return 1+suma(a,b-1);
    }
}
