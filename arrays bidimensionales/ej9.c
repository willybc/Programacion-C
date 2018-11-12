#include <stdio.h>

void carga(int f , int c , int m[][c]){
    int i,j;
    int num;
    for(i=0; i<f ; i++){
        for(j=0 ; j<c ; j++){
            scanf("%d",&num);
            m[i][j] = num;
        }
    }
}

void emitir ( int f , int c , int m[][c]){
    int i,j;
    for(i=0; i<f ; i++){
        for(j=0 ; j<c ; j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}

void comparacion ( int f , int c ,int m1[][c] , int m2[][c]){
    int i,j;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            if( m1[i][j] == m2[i][j]){
                printf("El elemento %d de la matriz 1 es comun a el elemento %d de la matriz 2 en la posicion [%d][%d]\n",m1[i][j],m2[i][j],i+1,j+1);
            }
        }
    }
}

int main() {

    const int F1 = 2;
    const int C1 = 2;

    const int F2 = 2;
    const int C2 = 2;

    int m1[F1][C1];
    int m2[F2][C2];

    printf("Escriba valores de matriz 1 \n");
    carga(F1, C1 ,m1);
    printf("Escriba valores de matriz 2 \n");
    carga(F2, C2 ,m2);

    printf("\nRegistros: \n");
    printf("Matriz 1:\n");
    emitir(F1 , C1 , m1);
    printf("Matriz 2:\n");
    emitir(F2,C2, m2);

    comparacion (F1,C1,m1,m2);

}

