#include <stdio.h>

void registro ( int f , int c , int m[][c]){
    int i,j;
    printf("Registros \n");
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            printf("%d\t",m[i][j]);
        }
    printf("\n");
    }
}

void caracol ( int f , int c , int m[][c]){
    int i,j;
    printf("\n");
    printf("Trayectoria Caracol \n");
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            if(i == 0){
                printf("%d ",m[i][j]);
            }
        }
    }

    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            if ( i == 0 && j == 3){

            }
            else{
                if( j == 3){
                printf("%d ",m[i][j]);
                }
            }
        }
    }

    for(i=3 ; i>=0 ; i--){
        for(j=2 ; j>=0 ; j--){
            if(i == 3){
                printf("%d ",m[i][j]);
            }
        }
    }

    for(i=0; i<f ; i++){
        for(j=0 ; j<c ; j++){
            if(i==0 && j==0){}
            else{
                if(i==3 && j==0){}
                else{
                    if (j==0){
                    printf("%d ",m[i][j]);
                    }
                }
            }
        }
    }

    for(i=0; i<f ; i++){
        for(j=0; j<c ; j++){
            if(i==1){
                if(j==0 || j==3){}
                else{
                    printf("%d ",m[i][j]);
                }
            }
        }
    }

    for(i=2 ; i>=0 ; i--){
        for (j=2; j>=0 ; j--){
            if(i==2){
                if(j==0 || j==3){}
                else{
                    printf("%d ",m[i][j]);
                }
            }
        }
    }
}

int main(){

    const int F = 4;
    const int C = 4;

    int m[4][4] = { 4,3,2,7,8,1,6,0,1,5,9,2,9,4,7,8};

    registro(F,C,m);
    caracol(F,C,m);

}
