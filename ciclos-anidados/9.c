#include <stdio.h>

int main () {

char i,a,e;

a='Z';

    for (e=a;e>='A';e--){

    for (i=a;i >='A';i--){
        printf ("%c", i);

    }
    a=a-1;
    printf("\n");
    }

return 0;

}
