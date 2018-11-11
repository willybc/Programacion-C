#include <stdio.h>

void captura ( int f , int c , int m[][c]){

    int i,j;
    int distrito , candidatoA, candidatoB , candidatoC;

    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            if(j == 0){
                printf("Escriba distrito \n");
                scanf("%d",&distrito);
                m[i][j] = distrito;
            }
            else{
                if(j == 1){
                printf("Candidado A? \n");
                scanf("%d",&candidatoA);
                m[i][j] = candidatoA;
                }
                else{
                    if(j == 2){
                    printf("Candidado B? \n");
                    scanf("%d",&candidatoB);
                    m[i][j] = candidatoB;
                    }
                    else{
                        if(j == 3){
                            printf("Candidado C? \n");
                            scanf("%d",&candidatoC);
                            m[i][j] = candidatoC;
                        }
                    }
                }
            }
        }
    }
}

void emitir ( int f , int c , int m[][c]){
    int i , j;

    for (i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}

int main(){

    const int F = 4;
    const int C = 4;

    int m[F][C];

    captura(F,C,m);
    emitir(F,C,m);

    getchar();
    return 0;
}

