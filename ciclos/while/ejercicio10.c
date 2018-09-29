#include <stdio.h>

int main(){

    int n , w , z, mcd;


    printf("Escriba valor de N\n");
    scanf("%d", &n);

    printf("Escriba valor de W\n");
    scanf("%d", &w);

    printf("Escriba valor de Z\n");
    scanf("%d", &z);

    while(n!=w){
        if (n>w)
            n -= w;
        else{
            w -= n;
        }
    }
    mcd = n;
    printf("El M.C.D. de %d y %d es %d\n", n, w, mcd);



}
