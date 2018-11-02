#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//alias  = typedef
typedef struct {
    char nombre[10];
    char fecha [10];
    char sexo;
    int edad;
}Datos;

void function2();

int main (){
    int r,i;
    int valor;
    FILE *arch;
    Datos undato = { "", "", 0, "" };
    arch = fopen("datos.txt","wb");

    if(arch == NULL){
        perror ("error abrir archivo");
        exit(1);
    }
    do{
        printf("Nombre? \n");
        scanf("%s",undato.nombre);

        printf("Sexo? \n");
        scanf(" %c",&undato.sexo);

        printf("Fecha ultimo pago de abono?\n");
        scanf("%s",undato.fecha);

        printf("Edad?\n");
        scanf("%d",&undato.edad);

        printf("\n1 para continuar / 0 para cerrar programa \n");
        scanf("%d",&valor);

    fwrite(&undato,sizeof(Datos),1,arch);
    }while(valor!=0);

    r = fclose(arch);

    if(r!=0){
        perror("error al cerrar");
        exit(1);
    }

    function2();
    return 0;
}

void function2(){
    int r,c;
    printf("\nRegistros : \n");
    FILE *arch2;
    Datos undato = { "", "", 0, "" };
    arch2 = fopen("datos.txt","rb");

    if(arch2 == NULL){
        perror ("error abrir archivo");
        exit(1);
    }
    while( !feof(arch2)){
        c=fread(&undato,sizeof(Datos),1,arch2);
        if(c == 1)
            printf("Nombre:%s\tSexo:%c\tPago:%s\tEdad:%d\n",undato.nombre,undato.sexo,undato.fecha,undato.edad);
    }
    r = fclose(arch2);
    if(r!=0){
        perror("error al cerrar");
        exit(1);
    }
    return 0;
}
