#include <stdio.h>

int main(){

    int n,m,p;

    printf("N?\n");
    scanf("%d",&n);

    printf("M?\n");
    scanf("%d",&m);

    printf("P?\n");
    scanf("%d",&p);

    if ( (n%m==0) && (n%p==0) ){
        printf("Es comun multiplo de M y P");
    }
    else{
        printf("N no es comun multiplo de M y P");
    }
    getchar();
}


