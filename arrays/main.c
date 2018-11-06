#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

#define N 10
int main()
{
    int v[N];
    int opcion;
    float prom;
    menu();

    printf("\nEscriba funcion\n");
    scanf("%d", &opcion);

    switch(opcion){
    case 1: leer(v);
            break;
    case 2: leerMarca(v);
            break;
    case 3: veces(5,v,0);
            break;
    case 4: invertirOrden(v);
            break;
    case 5: suma(v);
            break;
    case 6: resta(v);
            break;
    case 7: promedio(v);
            break;
    case 8: supera(v,prom);
            break;
    case 9: multiplo(v);
            break;
    case 10:maximo(v);
            break;
    case 11:pares(v);
            break;
    case 12:impares(v);
            break;
    case 13:posicion_par(v);
            break;
    }

    getchar();
    return 0;
}
