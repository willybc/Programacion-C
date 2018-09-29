#include <stdio.h>

int main(){

    char caracter;
    printf("Introduce un caracter y pulsa intro: ");
    scanf("%c", &caracter);

    if( (caracter >= 'A') && (caracter <= 'Z') ){
        printf("La letra es una mayuscula\n");
    }
    else if( (caracter >= 'a') && (caracter <= 'z') ){
        printf("La letra es una minuscula \n");
    }
    else if ( (caracter >= '0') && (caracter <= '9') ){
        printf("El caracter es un digito numero \n");
    }
    else{
        printf("No es una letra ni un digito numerico\n");
    }
}
