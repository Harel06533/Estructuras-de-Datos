/*
==== EJERCICIO 1 - MIÉRCOLES, MEMORIA DINÁMICA
*/
#include <stdio.h>
#include <stdlib.h>

int main () {
  int *pointer;

  //Inicializar tamaño
  pointer = malloc(64 * sizeof(int)); //Aloca 64 elementos, cada uno de 4 Bytes 
  *(pointer + 10) = 5000;

  //En caso de un fallo en la alocación de memoria termina el programa
  if (pointer == NULL) {
    fprintf(stderr, "Exit code 1, not possible to allocate the memory");
    exit(1);
  }

  //Imprimir
  for (int i = 0; i < 64; i++) {
    (i == 10) ? printf("%d - %p\n", pointer[i], pointer + i) : printf("%p\n", pointer + i);
  }

  //Liberar memoria
  free(pointer);
}
