#include <stdio.h>

int main(){

    int inv_pedro , tasa_pedro;
    int inv_jorge , tasa_jorge;
    int ano;

    printf("Cuanto invierte Pedro?\n");
    scanf("%d",&inv_pedro);

    printf("Con que tasa de ganancia anual?\n");
    scanf("%d",&tasa_pedro);

    printf("Cuanto invierte Jorge?\n");
    scanf("%d",&inv_jorge);

    printf("Con que tasa de ganancia anual?\n");
    scanf("%d",&tasa_jorge);

    ano=1;

    do{
        printf("\nEn el año %d : \n", ano);

        inv_pedro= ( ((inv_pedro * tasa_pedro)/100)+inv_pedro) ;
        printf("Pedro tendra una ganancia de %d\n",inv_pedro);

        inv_jorge= ( ((inv_jorge * tasa_jorge)/100)+inv_jorge) ;
        printf("Jorge tendra una ganancia de %d\n\n",inv_jorge);

        ano = (ano + 1);

    }while(inv_pedro<inv_jorge);

    printf("despues de %d años\n",ano);



}
