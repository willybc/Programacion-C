#include <stdio.h>

int main(){

    int ano;
    double a,b,c;

    ano=0;
    a= 55000000;
    b= 250000000;

    do{
        ano=(ano+1);
        printf("año %d\n",ano);
        a = (((a*8)/100)+a);
        printf("%.0lf\n",a);
        b = (((b*2)/100)+b);
        printf("%.0lf\n\n",b);
        c=(b/2);
    }while(a<c);

    printf("En %d años la poblacion A sera la mitad de B",ano);



}
