#include <stdio.h>

struct sucursales {
    int nro_sucursal;
    char localidad [30];
    float vus[7];
    float mv;
    float pv;
};
struct vendedores {
    int nro_vendedor;
    int nro_sucursal;
    char nom_vendedor[30];
};

int main(){
    const int N = 5;
    const int M = 5;
    const int X = 3;
    struct sucursales vsuc[N];
    struct vendedores vven[X];
    int v[N];
    int m[N][M];

    int cant_sin_ventas;
    cant_sin_ventas = ej4(N,vsuc,v);
}

void carga_vsuc( int f , struct sucursales vsuc[]){
    int i,j;
    for(i=0 ; i<f ; i++){
        vsuc[i].nro_sucursal = i+1;
        printf("Escriba localidad de sucursal %d \n",i+1);
        scanf(" %s",vsuc[i].localidad);
        for(j=0 ; j<7 ; j++){
            vsuc[i].vus[j] = 1+rand()%500;
        }
        vsuc[i].mv = 0;
        vsuc[i].pv = 0;
    }
}

void ej1(int f , struct sucursales vsuc[]){
    int i,j;
    float max;
    for(i=0 ; i<f ; i++){
        max=0;
        for(j=0 ; j<7 ; j++){
            if(vsuc[i].vus[j] > max){
                max = vsuc[i].vus[j];
            }
        }
        vsuc[i].mv = max;
    }
}

void carga_vven ( int f , struct vendedores vven[]){
    int i;
    for(i=0 ; i<f ; i++){
        vven[i].nro_vendedor = i+1;
        printf("Escriba su sucursal\n");
        scanf("%d",&vven[i].nro_sucursal);
        printf("Escriba su nombre\n");
        scanf(" %s", &vven[i].nom_vendedor);
    }
}

void ej2( int f , int x, struct sucursales vsuc[] , struct vendedores vven[]){
    int i;
    float max=0;
    int pos , nro_suc;
    for(i=0 ; i<f ; i++){
        if(vsuc[i].mv > max){
            max = vsuc[i].mv;
            pos = i;
            nro_suc = vsuc[i].nro_sucursal;
        }
    }
    for(j=0 ; j<x ; j++){
        if(vven[j].suc == nro_suc){
            printf("%s de sucursal %s obtuvo la mayor venta \n",vven[j].nom_vendedor,vsuc[pos].localidad);//revisar si vven[j].vendedor esta bien
        }
    }
}

void carga_m ( int f , int c , float m[][c]){
    int i,j;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            m[i][j] = 1+rand()%500;
        }
    }
}

void ej3( int f , int c , struct sucursales vsuc[] , float m[][c]){
    int i,j;
    float acu,cont;
    for(i=0 ; i<f ; i++){
        acu=0;
        cont=0;
        for(j=0 ; j<c ; j++){
            acu = acu + m[i][j];
            ++cont;
        }
        vsuc[i].pv = (acu/cont);
    }
}

void carga_v( int f , int v[]){
    int i;
    for(i=0 ; i<f ; i++){
        v[i] = -1;
    }
}

int ej4 ( int f , struct sucursales vsuc[] , int v[]){
    int i;
    int cant_sin_ventas;
    int pos;
    int cant=0;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<7 ; j++){
            if(vsuc[i].vus[j] == 0){
                cant_sin_ventas = 1;
                pos = i;
            }
        }
        if(cant_sin_ventas == 1){
            v[cant] = pos;
            cant++;
        }
    }
    return cant;
}

void ej6 (struct sucursales vsuc[] , int v[] , int cantidad ){
    for(i=0 ; i<cantidad ; i++){
        printf("%s no vendio \n",vsuc[v[i].localidad);
    }
//emitir las sucursales que no vendieron
}
//AL FINAL ORDENAR
void ej5 ( int f , struct sucursales vsuc[]){
    int i,j;
    for(i=0 ; i<f-1 ; i++){
        for(i=0 ; j<f-(1+i) ; j++{
            if(strcmp(vsuc[j].localidad,vsuc[j+1].localidad) > 0){
                aux = vsuc[j];
                vsuc[j] = vsuc[j+1];
                vsuc[j+1] = aux;
            }
        }
    }
}
