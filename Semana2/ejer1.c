#include <stdio.h>

void swap (int *num1, int *num2) {
  int aux; //Número auxiliar que permite guardar algún valor que se necesitará más adelante
  aux = *num1; //Se guarda el valor que se cambiará
  *num1 = *num2;
  *num2 = aux; //Se regresa
}

int main () {
  int a = 35, b = 40;
  printf("a = %d <-> b = %d\n", a, b);
  swap(&a, &b);
  printf("a = %d <-> b = %d", a, b);
  return 0;
}