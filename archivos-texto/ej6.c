#include <stdio.h>

int main (){

    FILE * arch;
    int r,tot,i;
    float nota1,nota2,nota3;
    float prom;
    char nombre[15],alu[7];
    arch = fopen ("alumnos.dat", "rt");

    if(arch == NULL){
        perror("error abrir archivo");
        exit(1);
    }

    while( !feof(arch)){
        fscanf(arch , "%s\t%f\t%f\t%f\n",nombre,&nota1,&nota2,&nota3);

        prom = ((nota1+nota2+nota3)/3);

        printf("nombre: %s nota1: %.0f nota2: %.0f nota3: %.0f prom: %.2f \n",nombre,nota1,nota2,nota3,prom);
    }

    //fprintf(arch, "%d", number)
    r = fclose (arch);

    if ( r != 0){
        perror ("error al cerrar");
        exit(1);
    }

    return 0;
}
