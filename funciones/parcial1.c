#include <stdio.h>
proceso();
function2 (char divisionx , float notax , int acumuladorx);

int main () {
    proceso();

    printf("Total de notas procesadas");
    printf("Promedio de todos los años y divison");
}

proceso () {

    int l, legajos;
    char division;
    int finciclo;
    float nota;
    float sumaA , sumaB, sumaC;
    int contadorA , contadorB, contadorC;
    float promA , promB, promC;
    int total_notas_procesadas;

    contadorA = 0;
    contadorB = 0;
    contadorC = 0;

    sumaA = 0;
    sumaB = 0;
    sumaC = 0;

    for(l= 1 ; l<=5 ; l++){
        printf("Proceso para año %d \n",l);

        do{
            do{
                printf("Division del alumno? (A) (B) (C) \n");
                scanf(" %c", &division);
                if(division == 'A' || division == 'B' || division == 'C'){
                    finciclo = 1;
                }
                else{
                    printf("ERROR #001 Escribir division correcta \n");
                    finciclo = 0;
                }
            }while(finciclo != 1);

            do{
                printf("Nota del alumno \n");
                scanf("%f", &nota);
                if( nota < 0 || nota > 10){
                    printf("ERROR #002 Escribir nota correcta (del 1 al 10) \n");
                }

                if( division == 'A'){
                    sumaA = sumaA + nota;
                    contadorA = contadorA + 1;
                }
                else{
                    if( division == 'B'){
                        sumaB = sumaB + nota;
                        contadorB = contadorB + 1;
                    }
                    else{
                        if ( division == 'C'){
                            sumaC = sumaC + nota;
                            contadorC = contadorC + 1;
                        }
                    }
                }

                promA = (sumaA / contadorA);
                promB = (sumaB / contadorB);
                promC = (sumaC / contadorC);

            }while(nota < 0 || nota > 10);

            printf("Legajo \n");
            scanf("%d", &legajos);

        }while(legajos != 0);

        /*
        printf("Año %d - promedio general", l);
        printf("A: %.2f \n", promA );
        printf("B: %.2f \n", promB );
        printf("C: %.2f \n", promC );
        */

        //PARA FUNCTION 2
        function2 ('A' , sumaA , contadorA);
        function2 ('B' , sumaB , contadorB);
        function2 ('C' , sumaC , contadorC);

        total_notas_procesadas = contadorA + contadorB + contadorC;

    }
}

function2 (char divisionx , float notax , int acumuladorx) {
    float prom;

    prom = (notax / acumuladorx);

    printf(" %c, %.2f \n", divisionx , prom);
}
