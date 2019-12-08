#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct empleado{
    int legajo;
    char nombre[15];
    char apellido[15];
    float sueldo;
    char fecha[15];
    char cargo[15];
};

int menu(){
    int opcion;
    printf("1 - abrir archivo\n");
    printf("2 - Leer y emitir datos en columnas con respectivos titulos \n");
    printf("3 - Buscar un elemento por legajo \n");
    printf("4 - Modificar un elemento \n");
    printf("5 - Ordenar los datos por apellido \n");
    printf("6 - Grabar datos ordenados en nuevo archivo \n");
    printf("7 - Emitir los datos ordenados \n");
    printf("8 - Dar de baja un elemento \n");
    scanf("%d", &opcion);
    fflush(stdin);
    return opcion;
}

void abrir(FILE *archivo){
    int r;
    archivo = fopen("empleados.txt", "r");
    if ( archivo == NULL) { perror("error al leer archivo\n"); exit(1);}
    else (printf("Se abrio correctamente el archivo \n") );

    fseek (archivo, 0 , SEEK_END);
    fflush(stdin);

    r = fclose(archivo);
    if ( r != 0){ perror ( "Error al cerrar archivo \n"); exit(1);}
    else (printf("Se cerro correctamente el archivo \n") );
    getchar();
}

void leerEmitir(FILE *archivo, int *cantemp){
    struct empleado emp;
    int r;
    int i=0;
    archivo = fopen("empleados.txt", "r");
    if ( archivo == NULL) { perror("error al leer archivo \n"); exit(1);}

    fread(&emp,sizeof(struct empleado), 1, archivo);
    fseek(archivo , 0, SEEK_END);

    *cantemp = ftell(archivo)/sizeof(struct empleado);
    printf("Empleados: \n");

    while( i < (*cantemp) ){
        fseek( archivo, i*sizeof(struct empleado), SEEK_SET);
        fread(&emp, sizeof(struct empleado), 1, archivo);
        printf("%d \t", emp.legajo);
        printf("%15s \t", emp.nombre);
        printf("%15s \t", emp.apellido);
        printf("%.2f \t", emp.sueldo);
        printf("%15s \t", emp.fecha);
        printf("%15s \n", emp.cargo);
        i++;
    }

    r = fclose(archivo);
    if( r != 0 ){ perror("error al cerrar archivo"); exit(1);}
}

int leerLegajo(){
    int leg;
    printf("Escriba el legajo del empleado \n");
    scanf("%d",&leg);
    fflush(stdin);
    return leg;

}
void buscaElemento(FILE *archivo){
    int leg;
    struct empleado emp;
    leg = leerLegajo();

    archivo = fopen("empleados.txt", "r");
    if( archivo == NULL){ perror("error al abrir el archivo"); exit(1);}

    while(!feof(archivo)){
        if(fread(&emp, sizeof(struct empleado), 1, archivo) == 1){
            if(leg == emp.legajo){
            printf("Legajo:%d \nNombre:%s \nApellido:%s \nSueldo:%.2f \nFecha:%s \nCargo:%s\n",emp.legajo, emp.nombre, emp.apellido, emp.sueldo, emp.fecha, emp.cargo);
            }
        }
    }
}

void modificaElemento(FILE *archivo){
    int leg;
    struct empleado emp;
    leg = leerLegajo();

    FILE * temp;

    archivo = fopen("empleados.txt", "r");
    temp = fopen("empleados.temp", "wt");
    if (archivo == NULL){ perror("error al abrir el archivo"); exit(1);}

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
        fwrite(&emp, sizeof(struct empleado), 1, temp);
    }

    fclose(archivo);
    fclose(temp);
    remove("empleados.txt");
    rename("empleados.temp","empleados.txt");
    remove("empleados.temp");
    printf("\nPrecio modificado correctamente \n");
    system("pause");
}
void ordenaPorApellido(FILE *archivo){
    struct empleado emp;
    struct empleado aux;
    int i;
    int j;
    int f;
    archivo = fopen("empleados.txt", "r");
    if ( archivo == NULL) { perror("Error al abrir el archivo "); exit(1);}

    while(!feof(archivo)){
        if(fread(&emp, sizeof(struct empleado), 1, archivo) == 1){



            for(i=0 ; i<f-1 ; i++){
                for(j=0 ; j<f-(i+1) ;j++){
                    if(strcmp(emp[j].apellido,emp[j+1].apellido) > 0){
                    aux = emp[j];
                        emp[j] = emp[j+1];
                        emp[j+1] = aux;
                    }
                }
            }
            printf("\n");
            for(i=0 ; i<f ; i++){
                printf(" %s\t",emp[i].apellido);
            }
            printf("\n");
        }
    }
}
void guardaOrdenados(FILE *archivo){}
void emitirOrdenados(FILE *archivo){}
void bajaElemento(FILE *archivo){}


int main(){
    int opcion;
    int cantemp;
    FILE *archivo;

    do{
        opcion = menu();
        switch(opcion){
            case 1 : abrir(archivo);
            break;
            case 2 : leerEmitir(archivo,&cantemp);
            break;
            case 3 : buscaElemento(archivo);
            break;
            case 4 : modificaElemento(archivo);
            break;
            case 5 : ordenaPorApellido(archivo);
            break;
            case 6 : guardaOrdenados(archivo);
            break;
            case 7 : emitirOrdenados(archivo);
            break;
            case 8 : bajaElemento(archivo);
            break;
        }
    }while(opcion != 0);
    getchar();
    return 0;
}
