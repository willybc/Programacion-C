#include <stdio.h>

struct sucursal {
    int num_sucursal;
    char localidad [30];
    float vus[7]; //ventas ultimas semanas
    float mv; // mayor venta - vacio
    float pv; // promedio ventas - vacio
};

struct vendedores {
    int num_vendedor;
    int num_sucursal;
    char nombre_vendedor [30];
};

int main(){
    const int N = 3;
    const int M = 3;
    const int X = 3;

    struct sucursal vsuc[N];
    struct vendedores vven[X];

    float m[N][M]; // ventas mensuales por sucursal

    int vpos[N]; // inicializara con -1

    carga_vsuc(N,vsuc);
    ej1(N,vsuc);

    carga_vven(N,vven);
    ej2(N,vsuc,vven);

    carga_matriz(N,M,m);
    ej3(N,M,vsuc,m);

    int cantSinVentas;
    carga_vector_pos(N,vpos);
    cantSinVentas = ej4(N,vsuc,vpos);
    printf("\n cant suc sin ventas = %d \n", cantSinVentas);

    ej5(N,vsuc);

    ej6(vsuc,vpos,cantSinVentas);
}

void carga_vsuc ( int f , struct sucursal vsuc[]){
    int i,j;

    for(i=0 ; i<f ; i++){
        vsuc[i].num_sucursal = i+1;
        printf("Escriba localidad para sucursal %d \n",i+1);
        scanf(" %s",vsuc[i].localidad);
        for(j=0 ; j<7 ; j++){
            vsuc[i].vus[j] = 0 + rand()%5;
        }
        vsuc[i].mv = 0;
        vsuc[i].pv = 0;
    }
    printf("\n");

    for(i=0; i<f ; i++){
        for(j=0 ; j<7 ; j++){
            printf("%.2f  ",vsuc[i].vus[j]);
        }
        printf("\n");
    }
}
void carga_vven ( int f , struct vendedores vven[]){
    int i;
    for ( i=0 ; i<f ; i++){
        vven[i].num_vendedor = i+1;
        vven[i].num_sucursal = i+1;
        printf("Escriba nombre del vendedor \n");
        scanf(" %s",vven[i].nombre_vendedor);
    }
}

void ej1 ( int f , struct sucursal vsuc[]){
    int i,j;
    for(i=0 ; i<f ; i++){
        for (j=0 ; j<7 ; j++){
            if (vsuc[i].vus[j] > vsuc[i].mv){
                vsuc[i].mv = vsuc[i].vus[j];
            }
        }
        printf("\nMaximo de venta %.2f \n",vsuc[i].mv);
    }
    printf("\n");
    //Cargue el campo mayor venta , la mayor venta detectada en el array
}

void ej2 ( int f , struct sucursal vsuc[] , struct vendedores vven[]){
    int i,j;
    int num_sucursal, pos;
    float max_venta=0;
    for(i=0 ; i<f ; i++){
            if( vsuc[i].mv > max_venta){
                max_venta = vsuc[i].mv;
                pos = i;
                num_sucursal = vsuc[i].num_sucursal;
            }
    }
    for(j=0 ; j<f ; j++){
        if( vven[j].num_sucursal == num_sucursal ){
            printf("Vendedor : %s de la sucursal %s \n",vven[j].nombre_vendedor , vsuc[pos].localidad);
        }
    }

//Emita el nombre del vendedor que obtuvo la mayor venta y nombre de sucursal a la que pertenece
}

void carga_matriz ( int f , int c , float m[][c]){
    int i,j;
    for ( i=0 ; i<f ; i++){
        for ( j=0 ; j<c ; j++){
            m[i][j] = 1+rand()%500;
        }
    }
}

void ej3( int f , int c , struct sucursal vsuc[] , float m[][c]){
    int i,j;
    float acu,cont;
    for(i=0 ; i<f ; i++){
        acu=0;
        cont=0;
        for(j=0 ; j<c ; j++){
            acu = acu + m[i][j];
            cont++;
        }
        vsuc[i].pv = acu/cont;
        printf("promedio venta : %.2f \n",vsuc[i].pv);
    }
    //que cargue el promedio de ventas en el campo promedio del vector de sucursales
}

void carga_vector_pos ( int f , int vpos[]){
    int i;
    for(i=0 ; i<f ; i++){
        vpos[i] = -1;
    }
}

int ej4 ( int f , struct sucursal vsuc[] , int vpos[] ){
    int i,j;
    int cant_venta;
    int cant=0;
    for(i=0 ; i<f ; i++){
        cant_venta = 0;
        for(j=0 ; j<7 ; j++){
            if( vsuc[i].vus[j] == 0) {
                cant_venta = 1;
            }
        }
        if( cant_venta == 1){
            vpos[cant] = i;
            cant++;
        }
    }
    return cant;
//Que cargue en este vector los registros del vector sucursales que tengan las 7 ventas iguales a cero
//(sucursales que no vendieron en la semana)
//debe retornar la cantidad de sucursales sin ventas detectada
}

void ej5 ( int f , struct sucursal vsuc[]){
    int i,j;
    struct sucursal aux;

    for(i=0 ; i<f-1 ; i++){
        for(j=0 ; j<f-(i+1) ;j++){
            if(strcmp(vsuc[j].localidad,vsuc[j+1].localidad) > 0){
                aux = vsuc[j];
                vsuc[j] = vsuc[j+1];
                vsuc[j+1] = aux;
            }
        }
    }
    printf("\n");
    for(i=0 ; i<f ; i++){
        printf(" %s\t",vsuc[i].localidad);
    }
    printf("\n");
//Ordenar por barrio
}

void ej6 (struct sucursal vsuc[] , int vpos[] , int cant ){
    int i;
    for(i=0 ; i<cant ; i++){
            printf(" %s no vendio \n",vsuc[vpos[i]].localidad);
    }

    //Emitir las sucursales que no vendieron
}

