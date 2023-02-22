// Semana 6 -> Lunes = Matriz piramidal

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Generar Número random basado en un límite y un comienzo
int lrand (const int start, const int limit) {
  return ((rand() % limit) + start);
}

//Main
int main () {
  srand(time(NULL));
  int **matrix;
  int currentCols = 0;
  int rowSize = lrand(2, 20);
  matrix = malloc(rowSize * sizeof(int *));
  if (matrix == NULL) {
    fprintf(stderr, "Error alocando memoria");
    exit(1);
  }

  /**
   * 1. Por cada fila de la matriz, se genera un número de colúmnas que equivale a cols + 1
   * 2. por cada fila y colúmna, se crea un número igual a cols + 1
   * 3. Imprime el contenido de los elemenos individuales de esa matriz
   * 4. Aumenta el valor de las cols para la siguiente iteración
  */
  for (int i = 0; i < rowSize; i++) {
    matrix[i] = malloc((currentCols + 1) * sizeof(int));
    if (matrix[i] == NULL) {
      fprintf(stderr, "Error alocando memoria");
      exit(1);
    }
    for (int j = 0; j < currentCols + 1; j++) {
      matrix[i][j] = currentCols + 1;
      printf(" %d ", matrix[i][j]);
    } 
    printf("\n");
    currentCols++;
  }
  return 0;
}