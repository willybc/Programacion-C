#include <stdio.h>

int main(){
    char nom[15];

    char sexo;
    int condicion;
    int legajo;
    int horas,sueldoxhora , sueldo;
    char respuesta;
    int n,i,j;
    int adelanto,adelanto_total,suma,adelantot;
    float prom_mas , prom_fem;
    int acu_fem , acu_mas;
    int contador_mas , contador_fem;

    suma = 0;

    adelanto=0;
    adelantot=0;
    acu_fem = 0;
    acu_mas = 0;

    contador_mas = 0;
    contador_fem = 0;
//INICIO DE CICLO FOR --------------------------------------------------------------------------------------------------
    for( i=0 ; i<3 ; i++ ){
// INICIO -----------------------------------------------------------------------------------------------
        printf("Escriba el nombre\n");
        scanf ("%s", nom);
        fflush(stdin);
        printf("Escriba m (masculino) o f (femenino)\n");
        printf("Escriba el sexo\n");
// SEXO ---------------------------------------------------------------------------------------------------------
         do{
            scanf ("%c", &sexo);
            fflush(stdin);
            if(sexo=='f' || sexo == 'm'){
                condicion = 1;
            }
            else{
                condicion = 0;
            }
           }while(condicion == 0);

// LEGAJO --------------------------------------------------------------------------------------------
        printf("Escriba su legajo \n");
        do{
            scanf("%d",&legajo);
            if(legajo<111 || legajo>999){
                printf("Error : legajo debe estar entre 111 & 999 \n");
            }
        }while(legajo<111 || legajo>999);

// FINAL DE LEGAJO ----------------------------------------------------------------------------

// TOTAL DE SUELDO POR HORA TRABAJAS  ----------------------------------------------------------------------------
            printf("Escriba horas\n");
            scanf("%d", &horas);
            fflush(stdin);
            printf("Escriba Sueldo por hora\n");
            scanf("%d", &sueldoxhora);
            fflush(stdin);
            sueldo = (sueldoxhora * horas);
            printf("\nsueldo deberia ser %d \n\n", sueldo);

// CONDICION SI RECIBIÓ ADELANTO ----------------------------------------------------------------------------------
            printf("Escribir (1) en caso de recibir adelanto en caso contraria escribir cualquier otra numero\n");
            scanf("%d",&respuesta);
            printf("----------------------------------------------------------------------------------------\n\n");

            if(respuesta == 1 ){
                printf("Cuantos adelantos pidio?\n");
                scanf("%d",&n);
                fflush(stdin);
                //SEGUNDA CONDICION FOR --------------------------------------------------------------------------
                for(j= 0 ; j<n ; j++){
                    printf("Ingrese adelanto\n");
                    scanf("%d", &adelanto);
                    fflush(stdin);
                    adelantot = adelanto + adelantot;
                }
                //FINAL DE SEGUNDA CONDICION FOR -----------------------------------------------------------------
                sueldo = (sueldo - adelantot);
            }
            else{
                printf("No pidio adelantos \n\n");
                printf("----------------------------------------------------------------------------------------\n\n");
            }
// CONDICION TERMINADA DE ADELANTO ------------------------------------------------------------------------------------

            if(sexo == 'f'){
            // ACUMULADOR DE SUELDOS FEMENINOS --------------------
            acu_fem = sueldo + acu_fem;
            // CONTADOR DE EMPLEADAS FEMENINAS --------------------
            contador_fem = (contador_fem+ 1);
            }

            if(sexo == 'm'){
            // ACUMULADOR DE SUELDOS MASCULINOS --------------------
                acu_mas = sueldo + acu_mas;
            // CONTADOR DE EMPLEADAS MASCULINAS --------------------
            contador_mas = (contador_mas+ 1);
            }
            printf("El empleado %s cobrara %d \n\n",nom,sueldo);
        }
//FINAL DE CICLO FOR --------------------------------------------------------------------------------------------------
        printf("\n");
        //printf("Hay %d hombres en la empresa \n",contador_mas );
        //printf("Hay %d mujeres en la empresa \n",contador_fem );
//PROMEDIO DE EMPLEADOS MASCULINOS = TOTAL DE SUELDOS MASCULINOS / TOTAL DE EMPLEADOS
        if(contador_mas == 0){
            printf("No hay empleados hombres\n");
        }else{
            prom_mas = ((float)(acu_mas/contador_mas));
        }

        if(contador_fem == 0){
            printf("No hay empleadas mujeres\n");
        }else{
            prom_fem = ((float)(acu_fem/contador_fem));
        }
//FINAL DE PROMEDIO DE EMPLEADOS MASCULINOS = TOTAL DE SUELDOS MASCULINOS / TOTAL DE EMPLEADOS

        printf("El total de pagos realizados a los empleados hombres es de %d \n",acu_mas);
        printf("El total de pagos realizados a los empleadas mujeres es de %d \n\n",acu_fem);

        printf("El promedio de los sueldos de hombres es de %.2f \n",prom_mas );
        printf("El promedio de los sueldos de mujeres es de %.2f \n\n",prom_fem );

        return 0;
    }




