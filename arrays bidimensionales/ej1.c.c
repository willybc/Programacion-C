#include <stdio.h>

int main(){

    int sp , ss;
    const int fil = 5;
    const int col = 5;

    int m[fil][col];

    cargar(fil,col,m);
    emitir(fil,col,m);

    getchar();
    return 0;
}


void cargar ( int f , int c , int m[][c]){
    int i , j , cont=1;

    for( i=0 ; i<f ; i++){

        for ( j=0 ; j<c ; j++){
            m[i][j]= cont;
            cont = cont+2;
        }
    }
}

void emitir( int f , int c , int m[][c]){
    int i,j;

    for(i=0 ; i<f; i++){
        printf("\n");

        for(j=0 ; j<c ; j++){
            printf("%d\t", m[i][j]);
        }
    }
}
