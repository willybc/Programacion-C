#include <stdio.h>

struct datos{
int id;
int mayor;
float promedio;
};

int main(){
    int sp , ss;
    const int fil = 5;
    const int col = 5;
    struct datos v[fil];

    int m[fil][col];
    cargar(fil,col,m);
    emitir(fil,col,m);

    printf("\n\n");

    sp = sumadp(fil, col, m);
	printf("sp = %d \n",sp);

    ss = sumass(fil, col, m);
    printf("ss = %d",ss);

    getchar();
    return 0;

}

int sumadp ( int f , int c , int m[][c]){
    int i,j,acu=0;
    for ( i=0 ; i<f ; i++){
        for ( j=0 ; j<c ; j++){
            if ( i == j){
                acu = acu + m[i][j];
            }
        }
    }
    return acu;
}

int sumass ( int f , int c , int m[][c]){
    int i,j,acu=0;
    for ( i=0 ; i<f ; i++){
        for ( j=0 ; j<c ; j++){
            if(i+j ==f-1){
                    acu = acu+m[i][j];
            }
        }
    }
    return acu;
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


/*
void cargarvector( int f, struct datosv[]){
    int i;

    for(i=0 ; i<f ; i++){
        v[i].id = i+1;
        v[i].mayor = 0;
        v[i]-promedio =0;
    }
}

void cargarmayor(int f, int c , int m[][c] , struct datosv[]){
    int i ,j, aux;

    for ( i=0 ; i<f ; i++){
        if(m[i][j] > aux){
            aux = m[i][j];
        }
    }
    v[i].mayor = aux;
}
*/
