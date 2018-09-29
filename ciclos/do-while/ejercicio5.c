#include <stdio.h>

int main(){

    int i, answer,contador,intentos;

    printf("Responde la siguiente pregunta\n");
    printf("tendras 4 intentos\n");
    printf("Buena suerte!\n");
    printf("\n");
    printf("Cuantas champions gano el Real Madrid?\n");

    contador=0;

    do{
        scanf("%d",&answer);
        contador= (contador +1);
        intentos = (4 - contador);
        if(answer==13){
                printf("Es Correcto!\n");
                return 0;
                }
                else{
                    if(contador==4){
                        printf("PERDISTE!, la respuesta es 13\n");
                    }
                    else{
                        printf("incorrecto ,te quedan %d intentos\n",intentos);
                    }
                }

    }while(contador<4);
}
