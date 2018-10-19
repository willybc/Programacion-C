#include <stdio.h>

int main (){

FILE *arch;

arch = fopen ("sueldos.dat","wt");

 if(arch == NULL){
        perror("error abrir archivo");
        exit(1);
    }

    fprintf(arch , "%s\t")


    r = fclose (arch);

    if ( r != 0){
        perror ("error al cerrar");
        exit(1);
    }

    return 0;

}
