#include <stdio.h>

void carga( int f , int c , int m[][c]){
    int i,j;
    int num;
    printf("Escriba valores \n");
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            scanf("%d",&num);
            m[i][j] = num;
        }
    }
}
int acu( int f , int c , int m[][c]){
    int i,j;
    int acu=0;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            acu = acu + m[i][j];
        }
    }
    return acu;
}

int main(){

    const int N = 2;
    const int M = 3;
    const int K = 4;

    int acu1,acu2 , producto;

    int m1[N][M];
    int m2[N][K];

    carga(N,M,m1);
    carga(N,K,m2);

    acu1 = acu(N,M,m1);
    printf("Acumulador 1 : %d \n",acu1);

    acu2 = acu(N,K,m2);
    printf("Acumulador 2 : %d \n",acu2);

    producto = acu1 * acu2;
    printf("Producto : %d \n",producto);
}
