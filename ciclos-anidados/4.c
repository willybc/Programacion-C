#include <stdio.h>

int main(){

int nota1, nota2, nota3, i , j;
float  prom;
char nom[15];

for( i=0 ; i <10 ; i++ ){

    printf("Escriba el nombre\n");
    scanf ("%s", nom);

    printf("Materia : Matematica Basica\n");
    printf("Escriba Nota 1\n");
    scanf("%d", &nota1);

    printf("Escriba Nota 2\n");
    scanf("%d", &nota2);

    printf("Escriba Nota 3\n");
    scanf("%d", &nota3);

    prom = ( (float)(nota1 + nota2 + nota3)/3) ;
    printf("El promedio de %s es de %.2f\n", nom , prom);

}
return 0;
}





