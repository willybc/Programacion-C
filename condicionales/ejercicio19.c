#include <stdio.h>
#include <string.h>

int main(){

    char a[1],b[1],c[1];

    printf("caracter 1 :");
    scanf("%c",&a);

    printf("caracter 2 :");
    scanf("%c",&b);

    printf("caracter 3 : \n");
    scanf("%c",&c);

    if(strcmp(a,b)>0){
        printf("%s,%s",a,b);
    }
    else{
        printf("%s,%s,%s",a,b);
    }


    return(0);
    getchar();

}

