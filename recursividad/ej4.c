#include <stdio.h>
int fibonacci( int n);

int main(){

    int n,i;
    int result;

    printf("NUMERO FIBONNACI ");

    result = fibonacci ( n);
    for ( i = 0 ; i <= 20 ; i++){
        printf("%d %d\n", i , fibonacci(i));
        getch();
    }
}

int fibonacci ( int n){

    if( n == 0){
        return 0;
    }
    else{
        if ( n == 1){
            return 1;
        }
        else{
            return fibonacci ( n -1) + fibonacci (n -2);
        }
    }

}
