#include <stdio.h>

void carga ( int f , int c , int m[][c]){
    int i,j,num;
    for(i=0 ; i<f ; i++){
        printf("Codigo %d :\n",i+101);
        for(j=0 ; j<c ; j++){
            switch(j){
                case 0 :    printf("Articulos vendidos el dia Lunes \n");
                            scanf("%d",&num);
                            m[i][j] = num;
                            break;

                case 1:     printf("Articulos vendidos el dia Martes \n");
                            scanf("%d",&num);
                            m[i][j] = num;
                            break;

                case 2:     printf("Articulos vendidos el dia Miercoles \n");
                            scanf("%d",&num);
                            m[i][j] = num;
                            break;

                case 3:     printf("Articulos vendidos el dia Jueves \n");
                            scanf("%d",&num);
                            m[i][j] = num;
                            break;

                case 4:     printf("Articulos vendidos el dia Viernes \n");
                            scanf("%d",&num);
                            m[i][j] = num;
                            break;
            }
        }
    }
}

void registro ( int f , int c , int m[][c]){
    int i,j;
    printf("\n");
    printf("Registros \n");
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<f ; j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}


int main(){

    const int F = 5;
    const int C = 5;

    int m[F][C];

    carga(F,C,m);

    registro(F,C,m);
}
