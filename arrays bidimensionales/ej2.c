#include <stdio.h>
void cargar ( int f , int c , int m[][c]){
    int i , j;

    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            m[i][j] = 0;
        }
    }
}

void emitir ( int f, int c , int m[][c]){
    int i,j;

    for(i=0; i<f ; i++){
        printf("\n");
        for(j=0; j<c ; j++){
            printf("%d ",m[i][j]);
        }
    }
}
int main(){

    const int fil = 20;
    const int col = 30;

    int m[fil][col];

    cargar(fil,col,m);
    emitir(fil,col,m);

    getchar();
    return 0;
}



