/* Muestra el resultado de la multiplicación de matríces desde los datos del .bin */
#include <stdio.h>
#include <stdlib.h>
#include "globals.h"

/*  Obtiene datos de un archivo binario a una matríz */
int **getMatFromFile (FILE *file, int r, int c) {
  int **matrix = malloc(c * sizeof(int *));
  for (int i = 0; i < r; i++) {
    matrix[i] = calloc(c, sizeof(int));
    fread(matrix[i], sizeof(int), c, file);
  }
  return matrix;
}

/* Imprime el resultado */
void printMatrix (int **matrix, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

 /* Liberar memoria de matríces */
void m_Free (int **matrix, int r, int c) {
  for (int i = 0; i < r; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int main () {

  /* Variables */
  FILE *valuefile = fopen("salida.bin", "rb");
  int **resultMatrix = getMatFromFile(valuefile, rows, cols);

  printf("Resultado de la multiplicación:\n");
  printMatrix(resultMatrix, rows, cols);

  fclose(valuefile);

  m_Free(resultMatrix, rows, cols);
  return 0;
}