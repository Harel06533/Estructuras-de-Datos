/*
Función matrix_copy
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Genera un número random y lo retorna
int lrand(int start, int limit) {return((rand() % limit) + start);}

/**
 * -- Copia una matriz en otra
 * 1. Parámetros:
 *  a. Matriz fuente
 *  b. Matriz destino
 *  c. Filas y columnas (puede optimizarse)
 * 2. Iguala cada elemento de la matriz destino con el de la matriz fuente
*/
void i_matCopy (int **source_m, int **dest_m, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      dest_m[i][j] = source_m[i][j];
    }
  }
}

/*Misma función para generar matriz*/
int **i_generateMatrix (int r, int c, bool isRandom) {
  int **matrix = malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++) {
    matrix[i] = calloc(c, sizeof(int));
    if (isRandom) {
      for (int j = 0; j < c; j++) {
        matrix[i][j] = lrand(0, 10);
      }
    }
  }
  return matrix;
}

//Main
int main () {
  int **matrix1;
  int **matrix2;
  int rows, cols;
  srand(time(NULL));

  //Datos del usuario
  printf("Introduzca las filas de la matriz = ");
  scanf("%d", &rows);
  printf("Introduzca las columnas de la matrix = ");
  scanf("%d", &cols);

  //Inicializar datos
  matrix1 = i_generateMatrix(rows, cols, true);
  matrix2 = i_generateMatrix(rows, cols, false);
  i_matCopy(matrix1, matrix2, rows, cols);

  //Matriz 1
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix1[i][j]);
    }
    printf("\n");
  }

  //Matriz 2
  printf("\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
  }

  return 0;
}

