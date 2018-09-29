#include <stdio.h>

void numero_par (int x);
void numero_multiplo (int y , int z);

int main() {

    int numero , numero2;
    printf("Escribe numero \n");
    scanf("%d",&numero);

    printf("Escriba variable n \n");
    scanf("%d" , &numero2);

    numero_par(numero);

    numero_multiplo(numero , numero2);
}

void numero_par (int x){

    if(x%2 == 0)
    printf("Es un numero par \n");
    else
    printf("Es un numero impar \n");
}

void numero_multiplo (int y , int z) {

    if(y % z == 0){
            printf("Es multiplo \n");
    }
    else{
        printf("No es multiplo \n");
    }

}
