#include <stdio.h>
void puntoa();
void puntob();

int main () {
    puntoa();
    puntob();
}

void puntoa(){
    int r;
    FILE *arch;
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

void puntob(){
    int f;
    FILE * arch;
    arch = fopen("prog1.sal", "wt");
    if( arch == NULL){
        perror("error abrir archivo");
        exit (1);
    }
    f = fclose (arch);
    if ( f != 0){
        perror ("error al cerrar");
        exit(1);
    }
    return 0;
}

