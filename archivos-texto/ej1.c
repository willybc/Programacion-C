#include <stdio.h>

int main () {
    int r;
    FILE *archivoh;
    arch = fopen("prog1.ent", "rt");

    if(arch == NULL){
        perror ("error abrir archivo");
        exit(1);
    }

    r = fclose(arch);

    if ( r !=0){
        perror ("error al cerrar");
        exit(1);
    }

    return 0;
}
