#include <stdio.h>

int main(){
    float nota;

    printf("Introduzca la nota del 0 al 10: ");
    scanf("%f", &nota);

    //Si nota es menor a 5
    if(nota <5){
        printf("SUSPENSION\n");
    }
    else{
         if(nota ==10){
            printf("SOBRESALIENTE");
         }
         else{
            if(nota >= 8){
            printf("NOTABLE");
            }
            else{
                printf("APROBADO \n");
            }
         }
    }
}

//si nota es == 5 , va aprobar porque no cumple la primera condicion
//si nota es menor a 5 lo SUSPENDEN
//si es mayor a 5 APRUEBA
