/*
=== CALCULAR PROMEDIO DE 2 NÚMEROS CON MEMORIA DINÁMICA ===
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
  //Valor asignado por el usuario
  int size;
  int *array;
  float sum = 0;

  printf("Introduzca el tamaño del arreglo: ");
  scanf("%d", &size);

  //Alocación dinámica de la memoria
  array = calloc(size, sizeof(int)); //Utilizo calloc porque viene bien para arreglos

  //En caso de que no se pueda alocar la memoria
  if (array == NULL) {
    printf("Alocación sin éxito, resultado 1\n");
    exit(1);
  }
  printf("\nSe alocaron %d espacios de %d Bytes (%d Bytes) de manera exitosa\n", size, sizeof(int), size * sizeof(int));

  for (int i = 0; i < size; i++) {
    printf("Número #%d: ", i + 1);
    scanf("%d", array + i);
    sum += array[i]; //Añade al valor a una suma
  }

  printf("El promeido de los números del arreglo es: %.2f", sum/size);
}