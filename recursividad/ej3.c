#include <stdio.h>
int producto ( int a , int b);

int main (){
    int a , b , result ;

    printf("valor a? \n");
    scanf("%d",&a);

    printf("valor b? \n");
    scanf("%d",&b);

    result = producto (a , b);
    printf("%d * %d = %d", a , b , result);
}

int producto ( int a , int b){

    if ( b == 0){
        return 0;
    }
    else{
        return a + producto (a, b-1);
    }

}
