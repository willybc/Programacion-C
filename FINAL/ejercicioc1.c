#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Empleado{
    int leg;                //legajo
    char ape[30];           //nombre
    char local[20];         //localidad
    char cat;               //categoria del empleado en la empresa
    float sueldoxhora;      //sueldo por hora
    int horastrab;          //cantidad de horas trabajadas
    float total;            //a calcular
    int valido;             //1 activo y 0 dado de baja
};

int menu(){
    int opcion;
    printf("1 - Lista de datos \n");
    printf("2 - Agregar empleado \n");
    printf("3 - Actualizar sueldo \n");
    printf("4 - Calcular sueldo total \n");
    printf("5 - Dar de baja(logica) por legajo y apellido \n");
    printf("6 - Eliminar a los dados de baja \n");
    scanf("%d", &opcion);
    fflush(stdin);
    return opcion;
}

void listaDatos(FILE *archivo , int *cantdatos){
    struct Empleado emp;
    int i=0;
    int r;
    archivo = fopen("empleados.dat","rb");
    if ( archivo == NULL ) { perror("error al abrir el archivo"); exit(1);}

    fread(&emp, sizeof(struct Empleado), 1, archivo);
    fseek(archivo, 0, SEEK_END);

    *cantdatos = ftell(archivo)/sizeof(struct Empleado);

    printf("Empleados:\n");

    while( i < (*cantdatos) ){
        fseek( archivo, i*sizeof(struct Empleado), SEEK_SET);
        fread(&emp, sizeof(struct Empleado), 1, archivo);
        if(emp.valido == 1){
            printf( " %-5d %-12s %-15s %-12c %-10.2lf %-12d %-10.2lf %-6d\n", emp.leg, emp.ape, emp.local, emp.cat, emp.sueldoxhora, emp.horastrab, emp.total, emp.valido);
            fflush(stdin);
        }
        i++;
    }
    r = fclose(archivo);
    if( r!=0 ) { perror ("error al cerrar archivo"); exit(1);}
}
void agregarEmpleados(FILE* archivo){
    struct Empleado emp;
    int r;
    archivo = fopen("empleados.dat", "r+b");
    if ( archivo == NULL ) { perror("error al abrir el archivo"); exit(1);}
    fseek(archivo, 0, SEEK_END);
    fflush(stdin);

    printf("ingrese legajo \n");
    scanf("%d", &emp.leg);
    fflush(stdin);

    printf("ingrese nombre \n");
    gets(emp.ape);
    fflush(stdin);

    printf("ingrese localidad \n");
    gets(emp.local);
    fflush(stdin);

    printf("ingrese categoria \n");
    scanf("%c",&emp.cat);
    fflush(stdin);

    printf("ingrese sueldo x hora \n");
    scanf("%f",&emp.sueldoxhora);
    fflush(stdin);

    printf("ingrese cant de horas trabajas \n");
    scanf("%d",&emp.horastrab);
    fflush(stdin);

    emp.valido = 1;

    fwrite(&emp, sizeof(struct Empleado), 1, archivo);
    r = fclose(archivo);
    if( r != 0) { perror ("error al cerar archivo"); exit(1);}
    getchar();

}

int leerLegajo(){
    int leg;
    printf("Escribe el legajo del empleado \n");
    scanf("%d",&leg);
    fflush(stdin);
    return leg;
}

void actualizarSueldo(FILE *archivo){
    struct Empleado emp;
    FILE * temp;

    archivo = fopen("empleados.dat","rb");

    temp = fopen("empleados.temp", "wb");
    if(temp == NULL){ perror("Error al abrir archivo empleados.temp \n"); exit(1);}

    fseek(archivo, 0, SEEK_SET);
    while(fread(&emp, sizeof(struct Empleado), 1, archivo)){
        if(emp.cat == 'B'){
            if(emp.local[0] == 'M'){
                emp.sueldoxhora = ( (emp.sueldoxhora * 0.10)+ emp.sueldoxhora );
            }

        }
        fwrite(&emp, sizeof(struct Empleado), 1, temp);
    }
    fclose(archivo);
    fclose(temp);

    remove("empleados.dat");
    rename("empleados.temp","empleados.dat");
    remove("empleados.temp");
    printf("Sueldo moficiado correctamente \n");
    system("pause");
}
void calcularSueldoTotal(FILE *archivo){
    struct Empleado emp;
    FILE *temp;

    archivo = fopen("empleados.dat","rb");
    temp = fopen("empleados.temp", "wb");

    fseek(archivo , 0, SEEK_SET);
    while(fread(&emp, sizeof(struct Empleado), 1, archivo)){
        emp.total = (emp.horastrab*emp.sueldoxhora);
        fwrite(&emp, sizeof(struct Empleado),1 , temp);
    }
    fclose(archivo);
    fclose(temp);

    remove("empleados.dat");
    rename("empleados.temp","empleados.dat");
    remove("empleados.temp");
    printf("Total de sueldos de los empleados calculado \n");
    system("pause");

}
void darBaja(FILE *archivo){
    int leg;
    char ape[30];
    struct Empleado emp;
    leg = leerLegajo();

    printf("Escriba el apellido \n");
    gets(ape);
    fflush(stdin);

    archivo = fopen("empleados.dat","r+b");
    if( archivo == NULL ) { perror("error al abrir el archivo \n"); exit(1);}

    while(!feof(archivo)){
        if(fread(&emp, sizeof(struct Empleado), 1, archivo) == 1 ){
            if ( leg == emp.leg ) {
                if( ape[0] == emp.ape[0] && ape[1] == emp.ape[1] && ape[2] == emp.ape[2] && ape[3] == emp.ape[3] && ape[4] == emp.ape[4]){
                    emp.valido = 0;
                    fseek(archivo, -sizeof(struct Empleado), SEEK_CUR);
                    fwrite(&emp, sizeof(struct Empleado), 1, archivo);
                    printf("Empleado dado de baja logicamente \n");
                    fflush(archivo);
                }
            }
        }
    }
    fclose(archivo);

    getchar();
}
void eliminarBaja(FILE *archivo){
    FILE *temp;
    struct Empleado emp;

    archivo = fopen("empleados.dat", "rb");
    temp = fopen("empleados.temp", "wb");

    fseek(archivo , 0 , SEEK_SET);
    while(fread(&emp, sizeof(struct Empleado), 1, archivo)){
        if(emp.valido == 1 ){
            fwrite(&emp, sizeof(struct Empleado),1, temp);
        }
    }
    fclose(archivo);
    fclose(temp);

    remove("empleados.dat");
    rename("empleados.temp","empleados.dat");
    remove("empleados.temp");

    printf("Empleados dados de baja eliminados \n");

}

main(){
    int opcion;
    int cantdatos;
    FILE *archivo;
    do{
        opcion = menu();
        switch (opcion){
            case 1 : listaDatos(archivo, &cantdatos);
            break;
            case 2 : agregarEmpleados(archivo);
            break;
            case 3 : actualizarSueldo(archivo);
            break;
            case 4 : calcularSueldoTotal(archivo);
            break;
            case 5 : darBaja(archivo);
            break;
            case 6 : eliminarBaja(archivo);
            break;
        }
    }while(opcion != 0);
    getchar();
    return 0;
}
