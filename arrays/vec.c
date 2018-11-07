#include "vec.h"
#include <stdio.h>
#include <string.h>

#define N 10

void carga ( int v[], int n){
    int i;
    for ( i=0; i <n ; i++){
        v[i] = i+1;
    }
}

void emitir ( int v[], int n) {
    int i;
    printf("Registros \n");
    for ( i=0;i<n;i++){
        printf("%d \n",v[i]);
    }
}

void leer ( int v[] ){
    int i,m;
    printf("Valor de elementos ? \n");
    scanf("%d",&m);
    for ( i=0; i<m; i++){
        v[i] = i+1;
    }
}

int leerMarca( int v[]){
    int i, a , contador=0;
    printf("Valor a ?\n");
    scanf("%d",&a);
    for( i=0 ; i<a; i++){
        v[i] = contador + i;
        if(i==a-1){
            printf("Numero de elementos leidos : %d \n",v[i]);
        }
    }
    return contador;
}

int veces ( int valor , int v[], int contador){
    int i;
    for ( i=0 ; i<N ; i++){
        printf("escriba valores\n");
        scanf("%d",&v[i]);

        if(v[i] == valor){
            contador++;
        }
    }
    printf("Numero de apariciones del elemento %d en el vector es de: %d",valor,contador);
}


void invertirOrden(int v[]){
    int i;
    carga(v,10);
    for ( i=9 ; i>=0 ; i--){
        printf("El valor de la posicion %d es :% d \n",i+1,v[i]);
    }
}

int suma ( int v[]){
    carga(v,10);
    int i, s=0;
    for ( i=0 ; i<N ; i++){
        s = s + v[i];
    }
    printf("Suma de todos los elementos : %d\n",s);
    return s;
}

int resta ( int v[]){
    carga(v,10);
    int i, r=0;
    for ( i=0 ; i<N ; i++){
        r = v[i] - r;
    }
    printf("Resta de todos los elementos : %d\n",r);
}

float promedio( int v[]){
    carga(v,10);
    int i,s=0;
    float p;
    for ( i=0 ; i<N ; i++){
        s = v[i] + s;
    }
    p = (float)s / N;
    printf("\nPromedio de todos los elementos : %.2f\n\n",p);
    return p;
}

void supera ( int v[], float prom){
    int i;
    carga(v,10);
    prom = promedio(v);
    printf("Valores que superaron el promedio:\n");
    for( i=0 ; i<N ; i++){
        if(v[i]> prom){
            printf("%d \n",v[i]);
        }
    }
}

void multiplo ( int v[]){
    int i,ult;
    carga(v,N);
    for(i=0 ; i<N ; i++){
        if ( i == N-1){
            ult = v[i]+1;
        }
    }

    for(i=0 ; i<N ; i++){
        if ( v[i] % ult == 0){
            printf("%d \n",v[i]);
        }
    }
}

int maximo ( int v[]){
    int i , max = -9999;
    carga(v,N);
    for ( i=0 ; i<N ; i++){
        if ( v[i] > max){
            max = v[i];
        }
    }
    printf("Maximo es %d \n",max);
//Cuenta cuantos max
   int j , cont=1;
   for ( j=0 ; j<N ; j++){
        if (v[i] == max){
        cont++;
        }
   }
   printf("Aparecio %d veces \n",cont);
//Ordena
    int h;
    for ( h=0 ; h<N ; h++){
        if ( v[i] == max){
            printf("El maximo aparece en posicion %d \n",i+1);
        }
    }
}

int pares ( int v[]){
    int i;
    carga(v,N);
    printf("Los siguientes valores son pares:\n");
    for ( i=0 ; i<N ; i++){
        if (v[i] % 2 == 0){
            printf("%d \n",v[i]);
        }
    }
}

int impares ( int v[]){
    int i;
    carga(v,N);
    printf("Los siguientes valores son impares:\n");
    for ( i=0 ; i<N ; i++){
        if (v[i] % 2 != 0){
            printf("%d \n",v[i]);
        }
    }
}

int posicion_par ( int v[]){
    int i;
    carga(v,N);
    printf("Los siguientes valores estan en posicion par:\n");
    for ( i=0 ; i<N ; i++){
        if ( i % 2 == 0){
            printf("%d \n",v[i]);
        }
    }
}

void menu(){
    int v[N];
    int opcion;
    float prom;

    printf("Menu de funciones\n");
    printf("1: Leer\n");
    printf("2: Leer elemento leidos con valor a\n");
    printf("3: Veces \n");
    printf("4: Invertir Orden \n");
    printf("5: Suma \n");
    printf("6: Resta \n");
    printf("7: Promedio \n");
    printf("8: Supera \n");
    printf("9: Multiplo \n");
    printf("10:Maximo,cantidad y orden \n");
    printf("11:Pares \n");
    printf("12:Impares \n");
    printf("13:Posiciones pares \n");
    printf("24:Programa de Sorteos \n");
    printf("\nEscriba funcion\n");
    scanf("%d", &opcion);

    switch(opcion){
    case 1: leer(v);
            break;
    case 2: leerMarca(v);
            break;
    case 3: veces(5,v,0);
            break;
    case 4: invertirOrden(v);
            break;
    case 5: suma(v);
            break;
    case 6: resta(v);
            break;
    case 7: promedio(v);
            break;
    case 8: supera(v,prom);
            break;
    case 9: multiplo(v);
            break;
    case 10:maximo(v);
            break;
    case 11:pares(v);
            break;
    case 12:impares(v);
            break;
    case 13:posicion_par(v);
            break;
    case 24:sorteo(v);
            break;
    }
}

void sorteo ( int v[]){
    int i,n,cont;
    printf("Programa de Sorteos \n");
    for ( i=0 ; i<10 ; i++){
        cont = 0;
        int v[54]={0};
        printf("Sorteo nro %d :",i+1);

        while ( cont < 6){
            n = rand()%54+1;
            if( v[n-1] == 0){
                printf("%d",n);
                if(cont < 6-1){
                    printf("-");
                }
                v[n-1]=1;
                cont ++;
            }
        }
        printf("\n");
    }
}

void prueba8(){
printf("Que sucede cuando declaramos lo siguiente \n\n");
printf("int vec[6]\n\n");
printf("y luego ejecutamos\n\nvec[6]=78?\n\n");
int vec[6],a;

a = (vec[6]=78);
printf("el valor de vec[6] sera : %d\n",a);
}

void prueba9(){
    int n=3;
    int edad,notas[n];
    edad=20; notas[n]=99;
    printf("Edad %d",edad);
    //No se esta usando el vector , ademas el v posicion 3 es el unico que valdra 99;
}

void prueba10(){
    /*
    int b[10];
    for ( i=0;i<=10;i++){
        b[i]=b[i+1];
    }
    */
    //no se declara i
    //b[i+1] esta incorrecto , en todo caso tendria que estar afuera de los corchetes
}

void prueba11(){
    /*
    int b[10];
    for ( i=0 ; i<10 ; i++){
        B[i] = b[i+1];
    }
    */
    //no se declara i
    //no se declara B
}
