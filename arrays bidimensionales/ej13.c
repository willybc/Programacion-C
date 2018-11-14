#include <stdio.h>

void cargar ( int f , int c , int m[][c]){
    int i,j,num;
    printf("Escriba valores \n");
    for(i=0 ; i<f ; i++){
        for (j=0; j<c ; j++){
            scanf("%d",&num);
            m[i][j] = num;
        }
    }
}
/*
void sumaMat( float mat1[] , float mat2[] , res[]) {
    int i , j;
    for (i=0 ; i<f ; i++){
        for (j=0; j<c ; j++){

        }
    }
}
*/

void registros( int f , int c , int m[][c]){
    int i,j;
    printf("\n");
    printf("Registros \n");
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}
int main() {

    const int F1 = 2;
    const int C1 = 3;

    const int F2 = 2;
    const int C2 = 3;

    int m1[F1][C1];
    int m2[F2][C2];

    cargar(F1,C1,m1);
    cargar(F2,C2,m2);

    registros(F1,C1,m1);
    registros(F2,C2,m2);

}

