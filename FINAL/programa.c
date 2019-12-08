#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct producto {
    int articulo;
    char marca[30];
    int stock;
    float precio;
    char valido;
};

void crearbin(FILE * archivo){
    if ( (archivo = fopen( "stock.dat", "w+b") ) == NULL ){
        printf("No pudo abrirse el archivo \n");
    }
    else{
        print("Archivo creado exitosamente \n");
        fclose ( archivo );
    }
    getchar();
}

void guardarDatos( FILE * archivo){
    struct producto prod;
    archivo = fopen("stock.dat", "r+b");
    fseek(archivo,0,SEEK_END);
    fflush(stdin);

    printf("Ingrese codigo numero del articulo \n");
    scanf("%d", &prod.articulo);
    fflush(stdin);

    printf("Ingrese marca del producto \n");
    gets(prod.marca);
    fflush(stdin);

    printf("Ingrese stock \n");
    scanf("%d", &prod.stock);
    fflush(stdin);
    while(prod.stock < 0 ){
        printf("El stock de un producto no puede ser netagivo. \n ingrese un valor correcto");
        printf("Ingrese sotkc \n");
        scanf("%d", &prod.stock);
    }

    prod.valido='S'

    fwrite(&prod, sizeof(struct producto), 1, archivo);
    fclose(archivo);
    getchar();

}

void emitirDatos ( FILE* archivo, int *cantprod){
    struct producto prod;
    int i=0;
    
    archivo = fopen("stock.dat", "rb");
    fread(&prod, sizeof(struct producto), 1, archivo);
    fseek(archivo, 0, SEEK_END);

    *cantprod = ftell(archivo)/sizeof(struct producto);
    printf("***Cantidad de acrticulos: %d *** \n",*cantprod);
    printf("Articulo\tMarca\t\tStock\t\tPrecio\tActivo\n");
    while(i<(*cantprod)){
        fseek(archivo, i*sizeof(struct producto), SEEK_SET);
        fseek(&prod, sizeof(struct producto), 1, archivo);
        printf("%-14d%-10s%13d%16.21f %8c\n", prod.articulo, prod.marca, prod.stock, prod.precio, prod.valido);
        i++;
    }
    fclose(archivo);
    getchar();
}

int leerArt(){
    int art;
    printf("Ingrese codigo numero del articulo: \n");
    scanf("%d", &art);
    return art;
}

void buscarProducto( FILE *archivo){
    struct producto prod;
    int art;
    art = leerArt();
    archivo = fopen("stock.dat","rb");
    while(!feof(archivo)){
        if(fread(&prod, sizeof(struct producto), 1, archivo) == 1) {
            if(art == prod.articulo){
                printf("Marca: %s\nArticulo: %d\nStock: %d\nPrecio: %.2f\n", prod.marca, prod.articulo, prod.stock, prod.precio);
            }
        }
    }
    fclose(archivo);
    getchar();
}

void modificarPrecio( FILE *archivo){
    int art;
    float nuevoPrecio, temporal;
    struct producto prod;
    FILE * temp;
    art = leerArt();
    printf("Ingrese nuevo precio \n");
    scanf("%f", &nuevoPrecio);
    
    while(nuevoPrecio <= 0){
        printf("El precio debe ser mayor a 0, ingrese nuevamente \n");
        printf("Ingrese nuevo precio \n");
        scanf("%f", &nuevoPrecio);
    }
    archivo = fopen("stock.dat", "r+b");
    temp = fopen("stock.temp", "wb");
    fseek(archivo, 0, SEEK_SET);
    while(fread(&prod, sizeof(struct producto ), 1, archivo)){
        if(prod.articulo == art){
            prod.precio = nuevoPrecio;
        }
        fwrite(&prod, sizeof(struct producto),1, temp);
    }
    fclose(archivo);
    fclose(temp);
    remove("stock.dat");
    rename("stock.temp","stock.dat");
    remove("stock.temp");
    printf("\n***--Precio modificado correctamente \n --***");
    system("pause");
}

void bajaLogica(FILE *archivo){
    int art;
    struct producto prod;
    art = leerArt();
    printf("\nArticulo leido es: %d", art);
    archivo = fopen("stock.dat", "r+b");
    while(!feof(archivo)){
        if(fread(&prod, sizeof(struct producto), 1, archivo) == 1){
            if(art == prod.articulo){
                prod.valido = 'N';
                fseek(archivo,-sizeof(struct producto), SEEK_CUR);
                fwrite(&prod, sizeof(struct producto), 1, archivo);
                fflush(archivo);
            }
        }
    }
    fclose(archivo);
    printf("\n***--El producto %d se dio de baja correctamente--***\n", art);
    getchar();
}

void bajaFisica (FILE *archivo){
    FILE *temp;
    struct producto prod;
    archivo = fopen("stock.dat","rb");
    temp = fopen("stock.temp","w+b");
    rewind(archivo);    //igual a fseek(archivo,0,SEEK_SET)
    while(fread(&prod, sizeof(struct producto), 1, archivo)){
        if(prod.valido == 'S'){
             fwrite(&prod, sizeof(struct producto), 1, temp)
        }
    }
    fclose(temp);
    fclose(archivo);
    remove("stock.dat");
    rename("stock.temp","stock.dat");
    remove("stock.temp");
    printf("\n***--Archivo actualizado--***\n");
}

int Menu(){
    char opcion;
    printf("Elije una opcion : \n");
    printf("C - Crear el archivo de texto \n");
    printf("G - Guardar el nuevo producto \n");
    printf("E - Lista de productos \n");
    printf("B - Buscar producto por articulo \n");
    printf("P - Moficiar precio \n");
    printf("O - Dar de baja logica de un prodcuto \n");
    printf("X - Actualizar archivo eliminando bajas de productos \n");
    printf("S - Salir \n");
    scanf("%c", &opcion);
    fflush(stdin);
    return toupper(opcion); //touper convierte minusculas a mayusculas
}

int main(){
    char opcion;
    int i,  cantprod;
    FILE *archivo;

    do{
        opcion=Menu();
        switch(opcion){
            case 'C': crearbin(archivo);
            break;
            case 'G': guardarDatos(archivo);
            break;
            case 'E': emitirDatos(archivo, &cantprod);
            break;
            case 'B': buscarProducto(archivo);
            break;
            case 'P': moficiarPrecio(archivo);
            break;
            case 'O': bajaLogica(archivo);
            break;
            case 'X': bajaFisica(archivo);
            break;            
        }
    }while(opcion != 'S');
    getchar();
    return 0;
}