#include <stdio.h>

void carga ( int f , int c , int m[][c]){
    int i,j;
    int num;
    printf("Escriba valores \n");
    for (i=0 ; i<f ; i++){
        for (j=0 ; j<c ; j++){
            scanf("%d",&num);
            m[i][j] = num;
        }
    }
}

void registros ( int f , int c , int m[][c]){
    int i,j;
    printf("\n");
    printf("Registros\n");
    for ( i=0 ; i<f ; i++){
        for (j=0 ; j<c ; j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}

void sumaColumnas ( int f , int c , int m[][c]){
    int i,j,acu;
    printf("\n");
    for(i=0 ; i<c ; i++){
        acu=0;
        for(j=0 ; j<f ; j++){
            acu = acu + m[j][i];
            //FALTA ORDENARLO DE MENOS A MAYOR
        }
        printf("La sumatoria de la columa %d : %d \n",i+1,acu);
    }
}

int main () {

    const int F = 4;
    const int C = 3;

    int m[F][C];

    carga(F,C,m);
    registros(F,C,m);
    sumaColumnas(F,C,m);

}

