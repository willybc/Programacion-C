#include <stdio.h>

int main(){
    char tab[3][2]={ {'C','A'},{'S','E'},{'C','O'}};
    int i,j;
    for(i=0 ; i<3 ; i++){
        for(j=0; j<2 ; j++){
            printf(" %c \t",tab[i][j]);
        }
    }
}
