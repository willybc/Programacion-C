#include <stdio.h>

void cargar(int f , int c , int m[][c]){
    int i,j,num,cont=0;
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
           /* printf("Vendedor : %d \n",i+1);
            printf("Escriba  cuanto vendio en zona %d \n",j+1);
            scanf("%d",&num);
            m[i][j] = num;
            */
            cont++;
            m[i][j] = cont;
        }
    }
}
//Se desea emitir el listado de zonas con su total por venta
int acumuladorZona ( int f, int c , int m[][c],int v[f]){
    int i,j,acu;
    for(i=0 ; i<c ; i++){
        acu=0;
        for(j=0 ; j<f ; j++){
            acu = acu + m[j][i];
            v[j] = acu;
            printf("%d",v[])
        }
        printf("Zona %d vendio un total de : %d \n",i+1,acu);
    }
}
//Ordenarlo de forma creciente por venta (menor a mayor)
void Ordenamiento(int f , int v[f]){
    int i,j,aux,cambio;
    for(i=0 ; i<f-1 ; i++){
        cambio=0;
        for(j=0 ; j<f-(i+1) ; j++){
            if( v[j] > v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                cambio = 1;
            }
        }
    }
}

void emiteV (int f , int v[f]){
    int i;
    for(i=0 ; i<f ; i++){
        printf("Zona %d :%d \n",i+1,v[i]);
    }
}

void emitir ( int f , int c , int m[][c]){
    int i,j;
    printf("\nRegistros:\n");
    for(i=0 ; i<f ; i++){
        for(j=0 ; j<c ; j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}

int main(){

    const int F = 5;
    const int C = 5;

    int m[F][C];
    int v[F];

    cargar(F,C,m);
    emitir(F,C,m);
    acumuladorZona(F,C,m,v);
    Ordenamiento(F,v);
    emiteV(F,v
           );
}
