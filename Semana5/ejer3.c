/*
=== LLENAR MATRIZ DE ENTEROS MEDIANTE MEMORIA DINÁMICA ===
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
  int rows, cols;
  int **matrix;
  srand(time(NULL));

  //Pedir datos al usuario
  printf("Introduzca los valores de las filas: ");
  scanf("%d", &rows);
  printf("Introduzca los valores de las columnas: ");
  scanf("%d", &cols);

  //Llenar memoria del primer índice de la matríz
  matrix = malloc(rows * sizeof(int *));

  //Llenar memoria del subíndice inferior de la matríz
  for (int i = 0; i < rows; i++) {
    matrix[i] = malloc(cols * sizeof(int)); //Cada subíndice se llena con el tamaño 
  }

  //Pequeño printf
  printf("Se ha alocado una matriz de %dx%d de enteros (%d Bytes Totales) exitosamente y este es el resultado:\n", rows, cols, rows * cols * sizeof(int));

  //Llenar e imprimir
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = rand () % 10;
      printf("%d ", matrix[i][j]);  
    }
    printf("\n");
  }
  return 0;
}