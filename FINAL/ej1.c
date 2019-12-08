#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct empleado{
    int legajo;
    char nombre[15];
    char apellido[15];
    float sueldo;
    char fecha[10];
    char cargo[10];
};

int menu(){
    int opcion;
    printf("Elegir una opcion \n");
    printf("1 - Grabar datos \n");
    printf("2 - Emision de datos \n");
    printf("3 - Busca datos mediante legajo \n");
    printf("4 - Modificacion de todos los datos del empleado por legajo \n");
    printf("5 - Aumento de sueldo (10porciento jefe / 15porciento resto) \n");
    printf("0 - Salir \n");
    scanf("%d",&opcion);
    return opcion;
}

void grabarDatos ( FILE * archivo){
    struct empleado emp;
    int r;
    archivo = fopen("empleados.txt", "a");//si no existe se crea
    if ( archivo == NULL) { perror("error al leer archivo"); exit(1);}
    fseek(archivo, 0, SEEK_END);
    fflush(stdin);

    printf("ingrese legajo \n");
    scanf("%d", &emp.legajo);
    fflush(stdin);

    printf("ingrese nombre \n");
    gets(emp.nombre);
    fflush(stdin);

    printf("ingrese apellido \n");
    gets(emp.apellido);
    fflush(stdin);

    printf("ingrese sueldo basico \n");
    scanf("%f",&emp.sueldo);
    fflush(stdin);

    while(emp.sueldo <= 0){
        printf("El sueldo no puede ser igual o menor a 0 \n");
        printf("Ingrese un valor correcto \n");
        scanf("%f",&emp.sueldo);
        fflush(stdin);
    }

    printf("ingrese fecha de nacimiento \n");
    gets(emp.fecha);
    fflush(stdin);

    printf("ingrese cargo \n");
    gets(emp.cargo);
    fflush(stdin);

    fwrite(&emp, sizeof(struct empleado), 1, archivo);
    r = fclose(archivo);
    if( r!= 0 ) { perror ("error al cerrar archivo"); exit(1);}
    getchar();
}

void emisionDatos(FILE *archivo, int *cantemp){
    struct empleado emp;
    int i=0;
    int r;

    archivo = fopen("empleados.txt", "r");
    if ( archivo == NULL) { perror("error al leer archivo"); exit(1);}

    fread(&emp, sizeof(struct empleado), 1, archivo);
    fseek(archivo, 0, SEEK_END);

    *cantemp = ftell(archivo)/sizeof(struct empleado);

    printf("Empleados:\n");

    while( i < (*cantemp) ){
        fseek( archivo, i*sizeof(struct empleado), SEEK_SET);
        fread(&emp, sizeof(struct empleado), 1, archivo);
        printf("%d\t%15s\t%15s\t%15.2f\t%10s\t%10s\t\n",emp.legajo, emp.nombre, emp.apellido, emp.sueldo, emp.fecha, emp.cargo);
        i++;
    }

    r = fclose(archivo);
    if( r!= 0 ) { perror ("error al cerrar archivo"); exit(1);}
}

int leerLegajo(){
    int leg;
    printf("Ingrese legajo de empleado\n");
    scanf("%d", &leg);
    fflush(stdin);
    return leg;
}

void buscaDatos( FILE *archivo ){
    //busca datos por legajo
    struct empleado emp;
    int leg;
    leg = leerLegajo();
    archivo = fopen("empleados.txt","r");
    while(!feof(archivo)){
        if(fread(&emp, sizeof(struct empleado), 1, archivo) == 1){
            if(leg == emp.legajo){
            printf("Legajo:%d \nNombre:%s \nApellido:%s \nSueldo:%.2f \nFecha:%s \nCargo:%s\n",emp.legajo, emp.nombre, emp.apellido, emp.sueldo, emp.fecha, emp.cargo);
            }
        }
    }
    fclose(archivo);
    getchar();
}
void modificacion( FILE *archivo ){
    //modificacion de todos los datos de empleado
    int leg;
    struct empleado emp;
    FILE * temp;
    leg = leerLegajo();

    archivo = fopen("empleados.txt", "r");
    temp = fopen("empleados.temp", "wt");
    fseek(archivo, 0, SEEK_SET);
    while(fread(&emp, sizeof(struct empleado), 1, archivo)){
        if(emp.legajo == leg){
                printf("Ingrese nombre modificado \n");
                gets(emp.nombre);
                fflush(stdin);

                printf("Ingrese apellido modificado \n");
                gets(emp.apellido);
                fflush(stdin);

                printf("Ingrese nuevo sueldo modificado \n");
                scanf("%f", &emp.sueldo);
                fflush(stdin);

                while(emp.sueldo <= 0){
                    printf("Sueldo debe ser mayor a 0 \n");
                    printf("Ingrese de nuevo el sueldo \n");
                    scanf("%f", &emp.sueldo);
                    fflush(stdin);
                }

                printf("Ingrese fecha de nacimiento modificado \n");
                gets(emp.fecha);
                fflush(stdin);

                printf("Ingrese cargo modificado \n");
                gets(emp.cargo);
                fflush(stdin);
        }
        fwrite(&emp, sizeof(struct empleado),1, temp);
    }

    fclose(archivo);
    fclose(temp);
    remove("empleados.txt");
    rename("empleados.temp","empleados.txt");
    remove("empleados.temp");
    printf("\n Precio modificado correctamente \n");
    system("pause");
}
void modificacionSueldo( FILE *archivo ){
    //10% de aumento a los jefes
    //15% al resto
    struct empleado emp;
    FILE *temp;

    archivo = fopen("empleados.txt", "r");
    temp = fopen("empleados.temp", "wt");
    fseek(archivo, 0, SEEK_SET);

    while(fread(&emp, sizeof(struct empleado), 1, archivo)){
        if(emp.cargo == 'jefe'){
            emp.sueldo = ((emp.sueldo * 0.10)+ emp.sueldo);
        }
        else{
            emp.sueldo = ((emp.sueldo * 0.15)+ emp.sueldo);
        }
        fwrite(&emp, sizeof(struct empleado), 1, temp);
    }

    fclose(archivo);
    fclose(temp);
    remove("empleados.txt");
    rename("empleados.temp","empleados.txt");
    remove("empleados.temp");
    printf("Aumento añadido \n");
    system("pause");

}

int main(){
    int opcion;
    int cantemp;
    FILE *archivo;

    do{
        opcion = menu();
        switch(opcion){
        case 1 : grabarDatos(archivo);
        break;
        case 2 : emisionDatos(archivo,&cantemp);
        break;
        case 3 : buscaDatos(archivo);
        break;
        case 4 : modificacion(archivo);
        break;
        case 5 : modificacionSueldo(archivo);
        break;
        }
    }while(opcion != 0);
    getchar();
    return 0;
}
