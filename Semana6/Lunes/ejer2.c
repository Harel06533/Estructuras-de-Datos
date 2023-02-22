/*
  * Multiplicación de Matrices
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//Genera un número random con un comienzo y límite
int lrand (int start, int limit) {
  return ((rand () % limit) + start);
}

/**
 * -ESTA FUNCIÓN RETORNA UNA MATRIZ CON VALORES RANDOM  
 * 1. Declara una matriz, donde cada elemento es un apuntador a entero
 * 2. Cada elemento inicial de la matriz, se convierte en un arreglo que vale c y se inicializa en 0
 * 3. Si isRandom es verdadero, entonces se llena la matriz con números random
 * 4. Retorna la matriz
*/
int **genRandMatrix(int r, int c, bool isRandom) {
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

/**
 * -ESTA FUNCIÓN IMPRIME LA MULTIPLICACIÓN DE 2 MATRÍCES Y RETORNA UNA NUEVA MATRÍZ CON LOS VALORES
 * 1. Genera una matriz que contendrá el resultado y será retornada
 * 2. Son 3 niveles de iteración el primero itera en las filas, el segundo en las columnas
 * 3. El tercer nivel itera también en las columnas, sin embargo se repetira ya que el primer renglón de m1 necesita multiplicarse con todas las filas de m2
 * 4. Retorna el resultado
*/
int **timesMatrix (int **m1, int **m2, int r, int c) {
  int **result = genRandMatrix(r, c, false);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int k = 0; k < c; k++) {
        result[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  return result;
}

//Imprimir las matrices
void printMatrix (int **matrix, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

//Main
int main () {
  srand(time(NULL));
  int **matrix1;
  int **matrix2;
  int **resultMatrix;
  int rows, cols;

  //Datos de usuario
  printf("Ingrese filas para ambas matrices: ");
  scanf("%d", &rows);
  printf("Ingrese columnas para ambas matrices: ");
  scanf("%d", &cols);

  //Genera ambas matrices y les pone valores random si su 3er argumento es verdadero, si no, inicializa en 0
  matrix1 = genRandMatrix(rows, cols, true);
  matrix2 = genRandMatrix(rows, cols, true);
  resultMatrix = timesMatrix(matrix1, matrix2, rows, cols);
  
  //Imprime las y el resultado de la multiplicación
  printf("\nMatrix 1:\n");
  printMatrix(matrix1, rows, cols);
  printf("\nMatrix 2:\n");
  printMatrix(matrix2, rows, cols);
  printf("\nMultiplicación Matrix:\n");
  printMatrix(resultMatrix, rows, cols);
}