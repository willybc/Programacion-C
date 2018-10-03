#include <stdio.h>
void function1( float * total_notas , float * mayor_prom_total , char * mayor_prom_div , int * mayor_prom_ano);
void function2(char division ,float nota ,float * acuA , float * acuB , float * acuC , float * conA , float * conB , float *conC);

int main(){
    float total_notas;
    float mayor_prom_total;
    char mayor_prom_div;
    int mayor_prom_ano;

    function1( &total_notas , &mayor_prom_total, &mayor_prom_div , &mayor_prom_ano);

    printf("El total de las notas procesadas es de %.1f \n", total_notas);
    printf("El mayor promedio de todos es de %.2f de la division %c y el año %d \n", mayor_prom_total , mayor_prom_div , mayor_prom_ano);
}

void function1( float * total_notas , float * mayor_prom_total , char * mayor_prom_div , int * mayor_prom_ano){
    int legajo , i;
    char division;
    float nota, promA , promB , promC;
    *mayor_prom_total = 0;


    for(i=1 ; i<=2 ; i++){

        float acuA = 0, acuB = 0, acuC = 0 , conA = 0 , conB = 0 , conC = 0;
        float mayor_prom;
        char mayor_div;
        int mayor_ano;

        printf("Año %d \n", i);

        printf("Escriba numero legajo \n");
        scanf("%d", &legajo);

        while(legajo !=0){

        printf("Escriba division del alumno (A) (B) (C) \n");
        scanf(" %c", &division);

        printf("Escriba la nota \n");

        scanf("%f", &nota);
        function2(division , nota , &acuA , &acuB , &acuC , &conA , &conB , &conC);

        printf("Escriba numero legajo \n");
        scanf("%d", &legajo);
        }

        promA = (acuA / conA);
        promB = (acuB / conB);
        promC = (acuC / conC);

        //MAYOR PROMEDIO
        if( promA > promB && promA > promC){
            mayor_prom = promA;
            mayor_div = division;
            mayor_ano = i;
        }
        else{
            if( promB > promA && promB > promC){
                mayor_prom = promB;
                mayor_div = division;
                mayor_ano = i;
            }
            else {
                if ( promC > promA && promC > promB){
                    mayor_prom = promC;
                    mayor_div = division;
                    mayor_ano = i;
                }
            }
        }
        //MAYOR PROMEDIO DE TODOS LOS AÑOS
        if (*mayor_prom_total < mayor_prom){
            *mayor_prom_total = mayor_prom;
            *mayor_prom_div = division;
            *mayor_prom_ano = i;
        }

        *total_notas =  *total_notas +(conA + conB + conC);

        printf("A, %.2f \n", promA);
        printf("B, %.2f \n", promB);
        printf("C, %.2f \n", promC);

        printf("\n");
        }
    }

void function2(char division ,float nota ,float * acuA , float * acuB , float * acuC , float * conA , float * conB , float *conC){

    switch (division){
          case 'A' : *acuA = *acuA + nota;
                     *conA = *conA + 1;
                     break;

          case 'B' : *acuB = *acuB + nota;
                     *conB = *conB + 1;
                     break;

          case 'C' : *acuC = *acuC + nota;
                     *conC = *conC + 1;
                     break;
    }

}
//Version sin posibles errores al dar valores de division , legajo y nota
