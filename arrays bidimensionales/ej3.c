#include <stdio.h>

void cargar(int f , int c , int m[][c]){
    int i ,j,aux;
    for(i=0; i<f ; i++){
        for(j=0; j<c ; j++){
            printf("Escriba valor [%d] [%d] :",i,j,aux);
            scanf("%d",&aux);
            m[i][j]=aux;
        }
    }
}

void emitirRegistros(int f, int c , int m[][c]){
    int i,j,cont=0,maxC=0;
    printf("Registros:\n");
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

void cantidadCeros(int f , int c , int m[][c]){
    int i,j,cont=0;
    for(i=0 ; i<f ; i++){
        for(j=0;j<c; j++){
            if (m[i][j] == 0){
                cont++;
            }
        }
    }
    printf("Cantidad de ceros : %d \n",cont);
}

void MaximoColumna(int f , int c , int m[][c]){
    int i,j,maxF;
    for(i=0 ; i<f ; i++){
            maxF=0;
        for(j=0 ; j<c ; j++){
            if (m[i][j] > maxF){
            maxF = m[i][j];
            }
        }
    printf("Maximo valor de fila %d : %d \n",i+1,maxF);
    }
}

void MinimoMatriz(int f , int c , int m[][c]){
    int i,j,minM=9999;
    int x=0,y=0;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            if (m[i][j] < minM){
                minM = m[i][j];
                x = i;
                y = j;
            }
        }
    }
    printf("Elemento menor de toda la matriz es : %d \n",minM);
    printf("En la fila : %d\n",x+1);
    printf("En la columna : %d\n",y+1);
}

void MaximoMatriz(int f , int c , int m[][c]){
    int i,j,maxM=-9999;
    int x=0,y=0;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            if (m[i][j] > maxM){
                maxM = m[i][j];
                x = i;
                y = j;
            }
        }
    }
    printf("Elemento mayor de toda la matriz es : %d \n",maxM);
    printf("En la fila : %d\n",x+1);
    printf("En la columna : %d\n",y+1);
}

void PromedioMatriz(int f , int c , int m[][c]){
    int i,j;
    float sum,cont=0 ,prom;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            sum = sum + m[i][j];
            cont++;
        }
    }

}

void PromedioFila(int f , int c , int m[][c]){
    int i,j;
    float sum,cont,prom,max_prom=-9999,max_fila=0;
    for(i=0 ; i<f ; i++){
    sum=0;cont=0;
        for(j=0 ; j<c ; j++){
                sum= sum + m[i][j];
                cont++;
        }
    prom = (sum/cont);
    printf("El promedio de fila %d es de : %.2f \n",i+1,prom);
    if( prom > max_prom){
      max_prom = prom;
      max_fila = i;
    }
    }
    printf("La fila que tiene el promedio maximo es %.0f con un promedio de : %.2f \n",max_fila+1,max_prom);
}

void negativos_y_positivos( int f , int c , int m[][c]){
    int i,j;
    int cont_pos=0, cont_neg=0;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            if(m[i][j] > 0){
                ++cont_pos;
            }
            else{
                ++cont_neg;
            }
        }
    }
    printf("Cantidad de positivos : %d \n",cont_pos);
    printf("Cantidad de negativos : %d \n",cont_neg);

}

int main(){

const int N = 3;
const int M = 5;

int m[N][M];

cargar(N,M,m);
emitirRegistros(N,M,m);
cantidadCeros(N,M,m);
//MaximoColumna(N,M,m);
/*
MinimoMatriz(N,M,m);
MaximoMatriz(N,M,m);

PromedioMatriz(N,M,m);
PromedioFila(N,M,m);
*/
negativos_y_positivos(N,M,m);




getchar();
return 0;

}
