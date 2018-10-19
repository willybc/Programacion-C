#include <stdio.h>

int main(){

    FILE *arch;
    int r , i ,number;

    printf("Ingrese un numero \n");
    scanf("%d", &number);

    arch = fopen("divis.dat","wt");

    if(arch == NULL){
        perror ("error abrir archivo");
        exit(1);
    }
/* IMPORTANT */
    for ( i=1 ; i<=number ; i++){
        if (number % i == 0){
            fprintf(arch , "%d \n", i);
        }
    }
/* IMPORTANT */
    r = fclose(arch);

    if (r != 0){
        perror ("error al cerrar");
        exit(1);
    }

    return 0;

}
