#include <stdio.h>
void function1 (float * cantidad_total_vent , char * zona_max_fact , int * contador_total_vent);
void function2 ( char zona , float venta , float * acu_N , float * acu_S , int * cont_vent_N , int * cont_vent_S);

int main () {

    float cantidad_total_vent;
    char zona_max_fact;
    int contador_total_vent;

    function1( &cantidad_total_vent , &zona_max_fact , &contador_total_vent);
    printf("Cantidad total de ventas ingresadas es de %d\n", contador_total_vent);
    printf("Zona que obtuvo mayor facturacion considerando todos los distribuidores es : %c \n", zona_max_fact);
    printf("Total general de ventas es de %.2f " , cantidad_total_vent);
}

void function1 (float * cantidad_total_vent , char * zona_max_fact , int * contador_total_vent) {
    int i , mino;
    char zona;
    float venta , acu_N , acu_S , zona_tot_acuN , zona_tot_acuS;
    int cont_vent_N , cont_vent_S;
    zona_tot_acuS = 0;
    zona_tot_acuN = 0;
    *contador_total_vent = 0;
    *cantidad_total_vent = 0;

    for( i = 1 ; i<=2 ; i++){
        printf("Distribuidora Nro : %d \n", i);
        acu_N = 0;
        acu_S = 0;
        cont_vent_N = 0;
        cont_vent_S = 0;

        printf("Nro cliente minorista\n");
        scanf("%d", &mino);

        while(mino != 0){

            printf("Zona (N o S) \n");
            scanf(" %c", &zona);

            printf("Venta \n");
            scanf("%f", &venta);

            function2 ( zona , venta , &acu_N , &acu_S , &cont_vent_N, &cont_vent_S);

        printf("numero de cliente minorista\n");
        scanf("%d", &mino);
        }

        //Zona mayor facturacion
        zona_tot_acuN = zona_tot_acuN + acu_N;
        zona_tot_acuS = zona_tot_acuS + acu_S;

        if (zona_tot_acuN > zona_tot_acuS){
            *zona_max_fact = 'N';
        }
        else{
            *zona_max_fact = 'S';
        }

        //Contador
        *contador_total_vent = ( *contador_total_vent + (cont_vent_N + cont_vent_S));

        //Total de ventas
        *cantidad_total_vent = *cantidad_total_vent + (acu_N + acu_S);

        printf("\n");
        printf("Zona N: %.2f \n", acu_N);
        printf("Zona S: %.2f \n", acu_S);
        printf("Total de venta: %d \n", (cont_vent_S + cont_vent_N));
        printf("\n");
        //TERMINA CLIENTE MINORISTA
    }
}

void function2 ( char zona , float venta , float * acu_N , float * acu_S , int * cont_vent_N , int * cont_vent_S) {

    switch (zona){
        case 'N' : *acu_N = *acu_N + venta;
                   *cont_vent_N = *cont_vent_N + 1;
                    break;
        case 'S' : *acu_S = *acu_S + venta;
                   *cont_vent_S = *cont_vent_S + 1;
                    break;
    }
}
