#include <stdio.h>

void CargaeImprime ( int f , int c , int m[][c]){
    int i,j,num;
    printf("Escriba valores de la matriz \n");
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            scanf("%d",&num);
            m[i][j] = num;
        }
    }
    printf("\nRegistros\n");
    for(i=0 ; i<f; i++){
        for(j=0 ; j<c ; j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}

void PromedioFila ( int f , int c , int m[][c], float promF[f]){
    int i,j;
    float suma=0 , cont=0;

    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            suma = suma + m[i][j];
            cont++;
        }
        promF[i] = (suma/cont);
        printf("Promedio de fila %d : %.2f \n",i+1,promF[i]);
    }
    printf("\n");
}

void PromedioColumna ( int f , int c , int m[][c], float promC[c]){
    int i,j;
    float suma=0 , cont=0;

    for(i=0 ; i<c ; i++){
        for(j=0 ; j<f ; j++){
            suma = suma + m[j][i];
            cont++;
        }
        promC[i] = (suma/cont);
        printf("Promedio de Columna %d : %.2f \n",i+1,promC[i]);
    }
    printf("\n");
}

void RestaxPromedio ( int f , int c , int m[][c], float promF[] , float promC[]){
    int i,j;
    float restaF,restaC;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            restaF = m[i][j] - promF[i];
            printf("Resultante de %d - %.2f (prom F) : %.2f \n",m[i][j],promF[i],restaF);

            restaC = m[i][j] - promC[i];
            printf("Resultante de %d - %.2f (prom C) : %.2f \n",m[i][j],promC[i],restaC);
        }
    }
}



int main(){

    const int F = 3;
    const int C = 3;

    int m[F][C];
    int promF[F];
    int promC[C];

    CargaeImprime(F,C,m);
    PromedioFila(F,C,m,promF);
    PromedioColumna(F,C,m,promC);

    RestaxPromedio(F,C,m,promF,promC);

}
