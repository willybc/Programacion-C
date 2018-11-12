#include <stdio.h>

void cargaV(int f , int v[f]){
    printf("Escriba valores del vector \n");
    int i,num;
    for(i=0 ; i<f ; i++){
        scanf("%d",&num);
        v[i] = num;
    }
}

void registrosV(int f , int v[f]){
    int i;
    printf("\nRegistros del Vector \n");
    for(i=0 ; i<f ; i++){
        printf("%d " , v[i]);
    }
    printf("\n");
}

int acumuladorV(int f , int v[f]){
    int i, acu=0;
    for(i=0 ; i<f ; i++){
        acu = acu + v[i];
    }
    return acu;
}

void registrosM ( int f , int c , int v[][c]){
    int i,j;
    printf("\nRegistros de la Matriz \n");
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            printf("%d ", v[i][j]);
        }
    printf("\n");
    }
}

void cargaM(int f , int c , int m[][c]){
    printf("Escriba valores de la matriz\n");
    int i,j,num;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            scanf("%d",&num);
            m[i][j] = num;
        }
    }
}

int acumuladorM ( int f , int c , int v[][c]){
    int i,j,acu=0;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            acu = acu + v[i][j];
        }
    }
    return acu;
}



int main() {

const int X = 3;

const int F = 3;
const int C = 3;

int m[F][C];
int v[X];

int acu1,acu2,mult;

cargaM(F,C,m);
cargaV(X,v);

registrosV(X,v);
registrosM(F,C,m);

acu1 = acumuladorV(X,v);
acu2 = acumuladorM(F,C,m);

printf("acu1 : %d \n",acu1);
printf("acu2 : %d \n",acu2);

mult = acu1 * acu2 ;
printf("mult : %d \n",mult);


}
