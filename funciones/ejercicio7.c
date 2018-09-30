#include <stdio.h>
void suma_intervalo( int x , int y) ;

int main(){
int x1, x2;

printf("Introduce dos valores \n");
scanf("%d", &x1);
scanf("%d", &x2);

suma_intervalo ( x1 , x2);
//printf("La suma de los valores de intervalo es : %d \n" , suma);
}

void suma_intervalo( int x , int y){
    int i , suma, contador , veces;
    contador = 0;

    if( x < y ) {
        veces = (y-x)+1;
    }
    else{
        veces = (x-y)+1;
    }

    printf("suma de intervalos [ %d , %d ] ", x , y);

    if ( x < y ) {

        for( i=1 ; i<=veces; i++){
            suma = x + y;
            y = y - 1;
            contador = contador + suma;
        }
        printf("es de %d \n", contador);
    }
    else{
        if (y < x) {
            for( i=1 ; i<=veces; i++){
                suma = x + y;
                contador = contador + suma;
                x = x - 1;
            }
            printf("es de %d \n", contador);
        }
    }
}
