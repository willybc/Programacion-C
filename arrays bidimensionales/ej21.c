#include <stdio.h>

void carga( int f , int c , int m[][c]){
    int i,j,cont=0;
    printf("Ingresa precios de los articulos \n");
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            cont++;
            m[i][j] = cont ;
        }
    }
}

void emitir ( int f , int c , int m[][c]){
    int i,j;
    printf("\nRegistros\n");
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}
//cómo debe calcular el dinero que le deben en total los 20 clientes
int dineroqueDeben( int f , int c , int m[][c]){
    int i,j,acu=0;

    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            acu = acu + m[i][j];
        }
    }
    return acu;
}
//cómo debe calcular el promedio de endeudamiento por cliente;
void promedioxCliente ( int f , int c , int m[][c]){
    int i,j,acu;
    int max=-9999;
    int posicionMax;
    for(i=0 ; i<f ; i++){
        acu=0;
        for(j=0 ; j<c ; j++){
            acu = acu + m[i][j];
        }
        printf("cliente numero %d debe : %d \n",i+1,acu);

//cómo puede saber qué cliente tiene una deuda mayor.

        if(acu > max){
            max = acu;
            posicionMax = i;
        }
    }
    printf("El cliente nro %d tiene la deuda mayor con : %d \n",posicionMax+1,max);
}


int main(){

    const int F = 5;
    const int C = 10;

    int m[F][C];

    int dinero;

    carga(F,C,m);
    emitir(F,C,m);

    dinero = dineroqueDeben(F,C,m);
    printf("El total de dinero que le deben es de %d \n",dinero);

    promedioxCliente(F,C,m);

}
