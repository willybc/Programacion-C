#include<stdio.h>

long potencia(int base , int expo);

int main(){
  int bas;
  int expo;
  int result;

  printf("Base?\n");
  scanf("%d", &bas);

  printf("Exponente ? \n");
  scanf("%d", &expo);

  result = potencia(bas , expo);
  printf("%d  ^  %d  = %d\n", bas , expo , result);

  return 0;
}

long potencia(int base , int exp)
{
  if (exp == 0)
    return 1;
  else
    return(base * potencia (base , exp-1));
}
