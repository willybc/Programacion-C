#include <stdio.h>

int main(){

int x1, x2, suma;

printf("Introduce dos valores ");

scanf("%d", &x1);
scanf("%d", &x2);

suma = suma_intervalo ( x1 , x2);

printf("La suma de los valores de intervalo es : %d" , suma);

}

suma_intervalo( x , y){
int i;
int total = 0;

for( i=x ; i<=y ; i++){
    total = total + x;
}


}
