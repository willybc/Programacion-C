#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

#define N 10
int main()
{
    int v[N];
    int opcion;
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

    }

    getchar();
    return 0;
}
