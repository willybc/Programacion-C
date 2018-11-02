#include <stdio.h>
#include <stdlib.h>
#include "vec.h"
int main()
{
    const int n = 5;
    int i , v[n];

    carga(v, n);
    emitir(v,n);
    getchar();

    return 0;
}

