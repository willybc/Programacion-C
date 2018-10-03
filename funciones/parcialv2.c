#include <stdio.h>
void function1();
void function2 ( char division , float nota , float *acA , float *acB , float *acC , float *cA , float *cB , float *cC);
int main () {
    function1();
}

void function1 () {

    int l, legajos , finciclo;
    char division;
    float nota;

    for(l= 1 ; l<=5 ; l++){

        float acA = 0;
        float acB = 0;
        float acC = 0;

        float cA = 0;
        float cB = 0;
        float cC = 0;

        float promA , promB , promC;

        printf("Proceso para año %d \n",l);

        printf("Legajo \n");
        scanf("%d", &legajos);

        while(legajos != 0){
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
            // FINAL DE DO WHILE ERROR DIVISION -->

            do{
                printf("Nota del alumno \n");
                scanf("%f", &nota);
                if( nota < 0 || nota > 10){
                    printf("ERROR #002 Escribir nota correcta (del 1 al 10) \n");
                }
            }while(nota < 0 || nota > 10);
            // FINAL DE DO WHILE ERROR NOTA -->
            function2 (division , nota , &acA , &acB , &acC , &cA, &cB , &cC);

            printf("Legajo \n");
            scanf("%d", &legajos);
        }
        // FINAL CICLO WHITE ERROR LEGAJO -->
                promA = (acA / cA);
                promB = (acB / cB);
                promC = (acC / cC);

                printf("promedio A : %.2f \n", promA);
                printf("promedio B : %.2f \n", promB);
                printf("promedio C : %.2f \n", promC);
        }
    // FINAL DE CICLO FOR -->
}

void function2 ( char division  , float nota , float *acA , float *acB , float *acC , float *cA , float *cB , float *cC){
    switch(division){
        case 'A': *acA = *acA + nota;
                  *cA = *cA +1;
                  break;
        case 'B': *acB = *acB + nota;
                  *cB = *cB +1;
                  break;
        case 'C': *acC = *acC + nota;
                  *cC = *cC +1;
                  break;
    }
}

